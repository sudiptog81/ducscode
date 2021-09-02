; doing bcd subtraction with 12345678H and 00000022H

.MODEL SMALL
.486
.DATA
    data1   DD    12345678H
    data2   DD    00000022H
    result  DD    ?
.CODE
.STARTUP
    MOV     EDX,  data1
    MOV     EBX,  data2
    
    SUB     DL,   BL
    MOV     AL,   DL
    DAS
    MOV     CL,   AL

    SBB     DH,   BH
    MOV     AL,   DH
    DAS
    MOV     CH,   AL

    BSWAP   ECX

    SHR     EBX,  16
    SHR     EDX,  16

    SBB     DL,   BL
    MOV     AL,   DL
    DAS
    MOV     CH,   AL

    SBB     DH,   BH
    MOV     AL,   DH
    DAS
    MOV     CL,   AL

    BSWAP   ECX

    MOV     result, ECX
.EXIT
END
