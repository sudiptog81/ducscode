.MODEL SMALL
.DATA
    prompt0 DB    'Enter Length of Array: $'
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

    ; LEA     DX,   msg3
    ; MOV     AH,   09H
    ; INT     21H

    LEA     SI,   array
    MOV     CX,   len

; print:
;     MOV     DL,   [SI]
;     MOV     AH,   02H
;     INT     21H
;     MOV     DL,   20H
;     MOV     AH,   02H
;     INT     21H
;     INC     SI
;     LOOP    print

search:
    MOV     BL,   [SI]
    CMP     AL,   BL
    JE      found
    INC     SI
    LOOP    search
    LEA     DX,   msg1
    MOV     AH,   09H
    INT     21H
    MOV     AH,   4CH
    INT     21H

found:
    LEA     DX,   msg2
    MOV     AH,   09H
    INT     21H
.EXIT
END
