.model small
.data
table dw one
      dw two
      dw three
      dw four
.code
.startup
top:  mov si, 4
      jmp table[si]
      one: mov dl, '1'
      mov ax, 1
      mov cx, 2
      add bx, 3
      two: mov dl, '2'
      mov ax, 2
      mov ax, 2
      add bx, 3
      three: mov dl, '3'
      mov ax, 2
      mov ax, 2
      add bx, 3
      four: mov dl, '4'
      mov ax, 2
      mov ax, 2
      add bx, 3
      bot: mov ah, 2
      int 21h
.exit
end
