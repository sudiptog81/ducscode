.MODEL SMALL
.486
.DATA

.CODE
.STARTUP
    MOV BX, 0101H
    MOV AX, 0404H
    MOV DX, 0202H
    MOV CX, 0101H
    
    MOV SI, AX
    
    MOV AL, DL
    ADD AL, BL
    DAA
    MOV DL, AL
    
    MOV AL, DH
    ADC AL, BH
    DAA
    MOV DH, AL
    
    MOV BX, SI
    
    MOV AL, BL
    ADC AL, CL
    DAA
    MOV CL, AL
    
    MOV AL, BH
    ADC AL, CH
    DAA
    MOV CH, AL
.EXIT
END
