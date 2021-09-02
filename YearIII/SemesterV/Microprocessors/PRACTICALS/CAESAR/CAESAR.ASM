.MODEL SMALL
.DATA
    prompt1    DB    'Enter plaintext: $'
    prompt2    DB    13, 'Enter ROT: $'
    message    DB    13, 'Plaintext: $'
    rotmessage DB    13, 10, 'ROT: $'
    plaintext  DB    100  DUP('$')
    ciphertext DB    100  DUP('$')
    rot        DB    100  DUP('$')
.CODE
.STARTUP
    MOV     DX,   OFFSET prompt1
    MOV     AH,   09H
    INT     21H

    MOV     SI,   OFFSET plaintext

input:
    MOV     AH,   01H
    INT     21H
    CMP     AL,   13
    JE      input_rot_prompt
    MOV     [SI], AL
    INC     SI
    JMP     input

input_rot_prompt:
    MOV     DX,   OFFSET prompt2
    MOV     AH,   09H
    INT     21H

    MOV     SI,   OFFSET rot

input_rot:
    MOV     AH,   01H
    INT     21H
    CMP     AL,   13
    JE      print
    MOV     [SI], AL
    INC     SI
    JMP     input_rot

print:
    MOV     DX,   OFFSET message
    MOV     AH,   09H
    INT     21H

    MOV     DX,   OFFSET plaintext
    MOV     AH,   09H
    INT     21H

    MOV     DX,   OFFSET rotmessage
    MOV     AH,   09H
    INT     21H

    MOV     DX,   OFFSET rot
    MOV     AH,   09H
    INT     21H

.EXIT
END
