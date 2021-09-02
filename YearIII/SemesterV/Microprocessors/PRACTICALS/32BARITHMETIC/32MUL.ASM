; multiplying two 32-bit user entered numbers

.MODEL SMALL
.486
.DATA
    prompt1    DB    'Enter the first 32-bit number: $'
    prompt2    DB    13, 10, 'Enter the second 32-bit number: $'
    message    DB    13, 10, '64-bit Product: $'
    operand    DD    ?
    resultms   DD    ?
    resultls   DD    ?
.CODE
.STARTUP
    ; prompt user for first number
    MOV     DX,   OFFSET prompt1
    MOV     AH,   09H
    INT     21H

    ; clear EBX for holding input
    XOR     EBX,  EBX

    ; initialise counter for loop
    MOV     CX,   04H

input1:
    ; shift content of EBX for next word
    SHL     EBX, 	8

    ; accept first digit
    MOV     AH,	  01H
    INT     21H

    ; check if it is a valid digit
    CMP     AL,   39H
    JBE     letter1

    ; adjust letters to hex
    SUB     AL,   37H

letter1:
    ; adjust hex characters to hex from ascii
    AND     AL,   0FH    ; mask contents in AL
    SHL     AL,   4      ; shift contents in AL
    MOV     BL,   AL

    ; accept second digit
    MOV     AH,   01H
    INT     21H

    ; check if it is a valid digit
    CMP     AL,   39H
    JBE     letter2

    ; adjust letters to hex
    SUB     AL,   37H

letter2:
    ; adjust hex characters to hex from ascii
    AND     AL,   0FH    ; mask contents in AL
    ADD     BL,   AL     ; adjust second digit in chunk

    LOOP    input1

    MOV     operand, 	 EBX

    ; prompt user for second number
    MOV     DX,   OFFSET prompt2
    MOV     AH,   09H
    INT     21H

    ; clear EBX for holding input
    XOR     EBX,  EBX

    ; initialise counter for loop
    MOV     CX,   04H

input2:
    ; shift content of EBX for next word
    SHL     EBX,  8

    ; accept first digit of chunk
    MOV     AH,   01H
    INT     21H

    ; check if it is a valid digit
    CMP     AL,   39H
    JBE     letter3

    ; adjust letters to hex
    SUB     AL,   37H

letter3:
    ; adjust hex characters to hex from ascii
    AND     AL,   0FH    ; mask contents in AL
    SHL     AL,   4      ; shift contents in AL
    MOV     BL,   AL

    ; accept second digit of chunk
    MOV     AH,   01H
    INT     21H

    ; check if it is a valid digit
    CMP     AL,   39H
    JBE     letter4

    ; adjust letters to hex
    SUB     AL,   37H

letter4:
    ; adjust hex characters to hex from ascii
    AND     AL,   0FH    ; mask contents in AL
    ADD     BL,   AL     ; adjust second digit in chunk

    LOOP    input2

    ; copy first number to EAX
    MOV     EAX,  operand

    ; multiply with the second number in EBX
    MUL     EBX

    ; copy results to memory
    MOV     resultms,   EDX
    MOV     resultls,   EAX

    ; print the result
    MOV     DX,   OFFSET message
    MOV     AH,   09H
    INT     21H

    ; copy the most significant part of product
    MOV     EBX,  resultms

    ; initalise the counter for loop
    MOV     CX,   04H

print1:
    ; rotate the contents of EBX
    ROL     EBX,  8
    
    ; convert hex to ascii
    MOV     AL,   BL
    AND     AL,   0F0H   ; mask contents in AL
    SHR     AL,   4      ; shift msb in AL
    ADD     AL,   30H    ; adjust hex to ascii

    CMP     AL,   39H    ; check if it is a digit
    JBE     print1sub1

    ADD     AL,   07H    ; adjust letters to ascii

print1sub1:
    ; print the first character of chunk
    MOV     DL,   AL
    MOV     AH,   02H
    INT     21H

    ; convert hex to ascii
    MOV     AL,   BL
    AND     AL,   0FH    ; mask contents in AL
    ADD     AL,   30H    ; adjust hex to ascii

    CMP     AL,   39H    ; check if it is a digit
    JBE     print1sub2

    ADD     AL,   07H    ; adjust letters to ascii

print1sub2:
    ; print the second character of chunk
    MOV     DL,   AL
    MOV     AH,   02H
    INT     21H

    LOOP    print1      ; loop until all digits are printed

     ; copy the least significant part of product
    MOV     EBX,  resultls

    ; initialise the counter for loop
    MOV     CX,   04H

print2:
    ; rotate the contents of EBX
    ROL     EBX,  8
    
    MOV     AL,   BL
    AND     AL,   0F0H   ; mask contents in AL
    SHR     AL,   4      ; shift msb in AL
    ADD     AL,   30H    ; adjust hex to ascii

    CMP     AL,   39H
    JBE     print2sub1

    ADD     AL,   07H    ; adjust letters to ascii

print2sub1:
    ; print the first character of chunk
    MOV     DL,   AL
    MOV     AH,   02H
    INT     21H

    MOV     AL,   BL
    AND     AL,   0FH    ; mask contents in AL
    ADD     AL,   30H    ; adjust hex to ascii

    CMP     AL,   39H    ; check if it is a digit
    JBE     print2sub2

    ADD     AL,   07H    ; adjust letter to ascii

print2sub2:
    ; print the second character of chunk
    MOV     DL,   AL
    MOV     AH,   02H
    INT     21H

    LOOP    print2     ; loop until all digits are printed
.EXIT
END
