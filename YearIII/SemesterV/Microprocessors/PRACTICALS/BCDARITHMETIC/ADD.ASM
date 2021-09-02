; doing bcd addition with 12345678H and 00000022H

.MODEL SMALL
.486
.DATA
    data1   DD    12345678H
    data2   DD    00000022H
    result  DD    ?
.CODE
.STARTUP
    MOV     EBX,  data1
    MOV     EDX,  data2
    
    ADD     DL,   BL
    MOV     AL,   DL
    DAA
    MOV     CL,   AL

    ADC     DH,   BH
    MOV     AL,   DH
    DAA
    MOV     CH,   AL

    BSWAP   ECX

    SHR     EBX,  16
    SHR     EDX,  16

    ADC     DL,   BL
    MOV     AL,   DL
    DAA
    MOV     CH,   AL

    ADC     DH,   BH
    MOV     AL,   DH
    DAA
    MOV     CL,   AL

    BSWAP   ECX

    MOV     result, ECX
.EXIT
END
