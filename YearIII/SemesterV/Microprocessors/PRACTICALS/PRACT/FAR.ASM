; to show jump to an instruction located in a different segment 
; than the current code segment, intersegment or far jump
.MODEL SMALL
.DATA
.CODE other
l1:
   MOV     AL, 1h
   JMP     far ptr l2
.CODE main
.STARTUP
   JMP     far ptr l1
l2:
.EXIT
END

