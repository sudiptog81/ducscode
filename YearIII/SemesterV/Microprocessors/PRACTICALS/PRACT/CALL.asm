.model small
.data  
.code two
move PROC far
  MOV AX, 0ffffh 
  RET
move ENDP
.code one
.startup
  MOV AX, 1h
  CALL move
.exit
END

