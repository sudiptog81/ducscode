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

### Fetch Sequence
