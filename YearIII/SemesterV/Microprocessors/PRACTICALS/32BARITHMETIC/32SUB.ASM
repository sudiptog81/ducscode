; subtracting 0000FFFFH from 12345678H

.MODEL SMALL
.DATA
    data1msb   DW   1234H
    data1lsb   DW   5678H
    data2msb   DW   0000H
    data2lsb   DW   0FFFFH
    resultlsb  DW   ?
    resultmsb  DW   ?
.CODE
.STARTUP
    MOV     AX,   data1lsb
    MOV     BX,   data1msb

    MOV     CX,   data2lsb
    MOV     DX,   data2msb

    SUB     AX,   CX
    SBB     BX,   DX

    MOV     resultlsb,  AX
    MOV     resultmsb,  BX
.EXIT
END
