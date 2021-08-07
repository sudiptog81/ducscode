.MODEL SMALL
.DATA
        DATA1   DB      34H
        DATA2   DB      12H
        DATA3   DW      0000H
        DATA4   DW      1111H
.CODE
.STARTUP
        MOV AL, DATA1
        MOV AH, DATA2
        MOV DATA3, AX
        MOV BX, DATA4
.EXIT
END
