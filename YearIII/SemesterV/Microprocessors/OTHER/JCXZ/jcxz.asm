.MODEL tiny
.DATA       
.CODE
.STARTUP

mov ax, 1
mov cx, 5

loop1:
inc ax
dec cx
jcxz loop2
jmp loop1

loop2:

.EXIT
END                                     ;
