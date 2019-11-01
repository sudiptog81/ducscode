; Displays "Hello!" on the screen
; Written by Sudipto Ghosh dor University of Delhi

section .data

    message db "Hello!", 10
    mlength equ $-message

section .text

global _start
_start:
    ; output program
    mov rax, 1           ; reg[rax] <- syscall to write() 
    mov rdi, 1           ; reg[rdi] <- file descriptor (stdout)
    mov rsi, message     ; reg[rsi] <- message text
    mov rdx, mlength     ; reg[rdx] <- message text length
    syscall              ; interrupt kernel

    ; exit program
    mov rax, 60          ; reg[rax] <- syscall to exit()
    mov rdi, 0           ; reg[rdi] <- exit code 0
    syscall              ; interrupt kernel

