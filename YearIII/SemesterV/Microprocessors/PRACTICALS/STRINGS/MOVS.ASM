.MODEL SMALL
.DATA
    abc        DB    'Hi$'
    def        DB    3  DUP('$')
.CODE
.STARTUP
    MOV     SI,   OFFSET abc
    MOV     DI,   OFFSET def 
    
    CLD
    MOV     CX,   04H    
    REP     MOVSB

    MOV     DI,   OFFSET def 

    LES     DL,   DI
    MOV     AH,   09H
    INT     21H
.EXIT
END
