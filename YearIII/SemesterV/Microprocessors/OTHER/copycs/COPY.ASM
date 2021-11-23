.model small
.data

.code
data1 dw 1234h

copy proc far
    mov ax, word ptr cs:data1
    mov bx, ax
    mov cx, bx
    mov dx, cx
    mov si, dx
    ret
copy endp

.startup
   mov ax, 0ffffh
   mov bx, ax
   mov cx, bx
   mov dx, cx
   mov si, dx
   call copy
.exit
end
