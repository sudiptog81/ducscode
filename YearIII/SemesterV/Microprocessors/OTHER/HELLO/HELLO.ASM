
.MODEL SMALL
.DATA       
.CODE
.STARTUP
        MOV AX, 65
        MOV DS, AX
                  
        MOV AH, 4CH                    
        INT 21H                       
        
END                                     ;
