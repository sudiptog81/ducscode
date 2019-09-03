# Basic CPU Design

## Registers

| Register | Description          | Size (b) |
| -------- | -------------------- | -------- |
| `dr`     | data register        | 16       |
| `ir`     | instruction register | 16       |
| `ac`     | accumulator          | 16       |
| `tr`     | temporary register   | 16       |
| `ar`     | address register     | 12       |
| `pc`     | program counter      | 12       |
| `inpr`   | input register       | 8        |
| `outr`   | output register      | 8        |
| `fgi`    | flag input           | 1        |
| `fgo`    | flag output          | 1        |
| `s`      | start-stop           | 1        |
| `e`      | carry out            | 1        |
| `i`      | indirect bit         | 1        |

## Condition Bits

| Name   | Register | Bit | Halt |
| ------ | -------- | --- | ---- |
| `halt` | s        | 0   | ✔    |

## Random-Access Memory

| Name   | Length | Cell Size |
| ------ | ------ | --------- |
| `main` | 4096   | 16        |

## Machine Instructions

### Input Fields

| Name        | Type     | Bits | Relativity | Default | Signed |
| ----------- | -------- | ---- | ---------- | ------- | ------ |
| `operation` | required | 16   | absolute   | 0       | ✔      |
| `opcode`    | required | 4    | absolute   | 0       | ✔      |
| `address`   | required | 12   | absolute   | 0       | ✔      |

### Instructions

| Instruction | Opcode | Format           |
| ----------- | ------ | ---------------- |
| `and`       | `0`    | `opcode address` |
| `add`       | `1`    | `opcode address` |
| `lda`       | `2`    | `opcode address` |
| `sta`       | `3`    | `opcode address` |
| `bun`       | `4`    | `opcode address` |
| `bsa`       | `5`    | `opcode address` |
| `isz`       | `6`    | `opcode address` |
| `and_i`     | `8`    | `opcode address` |
| `add_i`     | `9`    | `opcode address` |
| `lda_i`     | `A`    | `opcode address` |
| `sta_i`     | `B`    | `opcode address` |
| `bun_i`     | `C`    | `opcode address` |
| `bsa_i`     | `D`    | `opcode address` |
| `isz_i`     | `E`    | `opcode address` |
| `cla`       | `7800` | `operation`      |
| `cle`       | `7400` | `operation`      |
| `cma`       | `7200` | `operation`      |
| `cme`       | `7100` | `operation`      |
| `cir`       | `7080` | `operation`      |
| `cil`       | `7040` | `operation`      |
| `inc`       | `7020` | `operation`      |
| `spa`       | `7010` | `operation`      |
| `sna`       | `7008` | `operation`      |
| `sza`       | `7004` | `operation`      |
| `sze`       | `7002` | `operation`      |
| `hlt`       | `7001` | `operation`      |
| `inp`       | `F800` | `operation`      |
| `out`       | `F400` | `operation`      |
| `ski`       | `F200` | `operation`      |
| `sko`       | `F100` | `operation`      |
| `ion`       | `F080` | `operation`      |
| `iof`       | `F040` | `operation`      |

## Fetch Sequence

### ar <- pc

Micro Type: TransferRtoR

| name       | source | srcStartBit | dest | destStartBit | numBits |
| ---------- | ------ | ----------- | ---- | ------------ | ------- |
| `ar <- pc` | `pc`   | `0`         | `ar` | `0`          | `12`    |

### ir <- m[ar]

Micro Type: MemoryAccess

| name          | direction | memory | data | address |
| ------------- | --------- | ------ | ---- | ------- |
| `ir <- m[ar]` | `read`    | `main` | `ir` | `ar`    |

### pc <- pc + 1

Micro Type: Increment

| name           | register | overflowBit | delta |
| -------------- | -------- | ----------- | ----- |
| `pc <- pc + 1` | `pc`     | `halt`      | `1`   |

### i <- ir (15)

Micro Type: TransferRtoR

| name           | source | srcStartBit | dest | destStartBit | numBits |
| -------------- | ------ | ----------- | ---- | ------------ | ------- |
| `i <- ir (15)` | `ir`   | `0`         | `i`  | `0`          | `1`     |

### ar <- ir (0-11)

Micro Type: TransferRtoR

| name              | source | srcStartBit | dest | destStartBit | numBits |
| ----------------- | ------ | ----------- | ---- | ------------ | ------- |
| `ar <- ir (0-11)` | `ir`   | `4`         | `ar` | `0`          | `12`    |

### decode ir

Micro Type: Decode

| name        | ir   |
| ----------- | ---- |
| `decode ir` | `ir` |

## Execution Options

- **Code Store**: `main`
- **Starting Address**: `33` (dec)

## Initial Values of Registers

- `ac` : `A937`
- `e` : `1`
- `pc` : `021`

## Register Reference Instructions

### CLA [`7800`]

#### ac <- 0

Micro Type: Set

| name      | register | start | numBits | value |
| --------- | -------- | ----- | ------- | ----- |
| `ac <- 0` | `ac`     | `0`   | `16`    | `0`   |

#### End

### CLE [`7400`]

#### e <- 0

Micro Type: Set

| name     | register | start | numBits | value |
| -------- | -------- | ----- | ------- | ----- |
| `e <- 0` | `e`      | `0`   | `1`     | `0`   |

#### End

### CMA [`7200`]

#### ac <- ac'

Micro Type: Logical

| name        | type  | source1 | source2 | destination |
| ----------- | ----- | ------- | ------- | ----------- |
| `ac <- ac'` | `NOT` | `ac`    | `ac`    | `ac`        |

#### End

### CME [`7100`]

#### e <- e'

Micro Type: Logical

| name      | type  | source1 | source2 | destination |
| --------- | ----- | ------- | ------- | ----------- |
| `e <- e'` | `NOT` | `e`     | `e`     | `e`         |

#### End

### CIR [`7080`]

#### e <- ac (0)

Micro Type: TransferRtoR

| name          | source | srcStartBit | dest | destStartBit | numBits |
| ------------- | ------ | ----------- | ---- | ------------ | ------- |
| `e <- ac (0)` | `ac`   | `15`        | `e`  | `0`          | `1`     |

#### ac <- shr ac

Micro Type: Shift

| name           | source | destination | type     | direction | distance |
| -------------- | ------ | ----------- | -------- | --------- | -------- |
| `ac <- shr ac` | `ac`   | `ac`        | `cyclic` | `right`   | `1`      |

#### ac (15) <- e

Micro Type: TransferRtoR

| name           | source | srcStartBit | dest | destStartBit | numBits |
| -------------- | ------ | ----------- | ---- | ------------ | ------- |
| `ac (15) <- e` | `e`    | `0`         | `ac` | `0`          | `1`     |

#### End

### CIL [`7040`]

#### e <- ac (15)

Micro Type: TransferRtoR

| name           | source | srcStartBit | dest | destStartBit | numBits |
| -------------- | ------ | ----------- | ---- | ------------ | ------- |
| `e <- ac (15)` | `ac`   | `0`         | `e`  | `0`          | `1`     |

#### ac <- shl ac

Micro Type: Shift

| name           | source | destination | type     | direction | distance |
| -------------- | ------ | ----------- | -------- | --------- | -------- |
| `ac <- shl ac` | `ac`   | `ac`        | `cyclic` | `left`    | `1`      |

#### ac (0) <- e

Micro Type: TransferRtoR

| name          | source | srcStartBit | dest | destStartBit | numBits |
| ------------- | ------ | ----------- | ---- | ------------ | ------- |
| `ac (0) <- e` | `e`    | `0`         | `ac` | `15`         | `1`     |

#### End

### INC [`7020`]

#### ac <- ac + 1

Micro Type: Increment

| name           | register | overflowBit | delta |
| -------------- | -------- | ----------- | ----- |
| `ac <- ac + 1` | `ac`     | `halt`      | `1`   |

#### End

### SPA [`7010`]

#### if (ac (15) = 0)

Micro Type: Test

| name               | register | start | numBits | comparison | value | omission |
| ------------------ | -------- | ----- | ------- | ---------- | ----- | -------- |
| `if (ac (15) = 0)` | `ac`     | `0`   | `1`     | `EQ`       | `0`   | `1`      |

#### End

#### pc <- pc + 1

Micro Type: Increment

| name           | register | overflowBit | delta |
| -------------- | -------- | ----------- | ----- |
| `pc <- pc + 1` | `pc`     | `halt`      | `1`   |

#### End

### SNA [`7008`]

#### if (ac (15) = 1)

Micro Type: Test

| name               | register | start | numBits | comparison | value | omission |
| ------------------ | -------- | ----- | ------- | ---------- | ----- | -------- |
| `if (ac (15) = 1)` | `ac`     | `0`   | `1`     | `EQ`       | `1`   | `1`      |

#### End

#### pc <- pc + 1

Micro Type: Increment

| name           | register | overflowBit | delta |
| -------------- | -------- | ----------- | ----- |
| `pc <- pc + 1` | `pc`     | `halt`      | `1`   |

#### End

### SZA [`7004`]

#### if (ac = 0)

Micro Type: Test

| name          | register | start | numBits | comparison | value | omission |
| ------------- | -------- | ----- | ------- | ---------- | ----- | -------- |
| `if (ac = 0)` | `ac`     | `0`   | `16`    | `EQ`       | `0`   | `1`      |

#### End

#### pc <- pc + 1

Micro Type: Increment

| name           | register | overflowBit | delta |
| -------------- | -------- | ----------- | ----- |
| `pc <- pc + 1` | `pc`     | `halt`      | `1`   |

#### End

### SZE [`7002`]

#### if (e = 0)

Micro Type: Test

| name         | register | start | numBits | comparison | value | omission |
| ------------ | -------- | ----- | ------- | ---------- | ----- | -------- |
| `if (e = 0)` | `e`      | `0`   | `1`     | `EQ`       | `0`   | `1`      |

#### End

#### pc <- pc + 1

Micro Type: Increment

| name           | register | overflowBit | delta |
| -------------- | -------- | ----------- | ----- |
| `pc <- pc + 1` | `pc`     | `halt`      | `1`   |

#### End

### HLT [`7001`]

#### halt <- 1

Micro Type: SetCondBit

| name        | bit    | value |
| ----------- | ------ | ----- |
| `halt <- 1` | `halt` | `1`   |

#### End
