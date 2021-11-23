.MODEL SMALL
.DATA
    prompt0 DB    'Enter Length of Array (<=10): $'
    prompt1 DB    13, 10, 'Enter Elements: $'
    prompt2 DB    13, 10, 'Enter Key: $'
    msg1    DB    13, 10, 'Element Not Found in array!$'
    msg2    DB    13, 10, 'Element Found in array!$'
    array   DB    10 DUP(?)
    len     DW    ?
    key     DB    ?
.CODE
.STARTUP
    LEA     DX,   prompt0
    MOV     AH,   09H
    INT     21H

    MOV     AH,   01H
    INT     21H
    MOV     AH,   00H
    SUB     AL,   30H
    MOV     len,  AX

    LEA     DX,   prompt1
    MOV     AH,   09H
    INT     21H

    LEA     SI,   array
    MOV     AL,   key
    MOV     CX,   len

input:
    MOV     AH,   01H
    INT     21H
    MOV     [SI], AL
    INC     SI
    MOV     DL,   20H
    MOV     AH,   02H
    INT     21H
    LOOP    input

    LEA     DX,   prompt2
    MOV     AH,   09H
    INT     21H

    MOV     AH,   01H
    INT     21H
    MOV     key,  AL

    LEA     SI,   array
    MOV     CX,   len

search:
    MOV     BL,   [SI]
    CMP     AL,   BL
    JE      found
    INC     SI
    LOOP    search
    LEA     DX,   msg1
    MOV     AH,   09H
    INT     21H
    JMP     final

found:
    LEA     DX,   msg2
    MOV     AH,   09H
    INT     21H

final:
.EXIT
END
