; Prompts user, takes input, prints output
; Written by Sudipto Ghosh for University of Delhi

section .bss

    buffer: resb 2

section .data

    msg: db "You entered", 0
    prompt_msg: db "Enter an integer: ", 0

section .text

global _start
_start:
    call prompt
    call scan    
    call print
    call printoutput
    call exit

scan:
    mov eax, 0           ; eax <- read()
    mov edi, 0           ; edi <- 0 (stdin)
    mov rsi, buffer     ; rsi <- rsp-8 (buffer)
    mov edx, 2           ; edx <- 2 characters (1+newline)
    syscall  
    ret

prompt:
    mov eax, 1           ; eax <- write()
    mov edi, 1           ; edi <- 1 (stdout)
    mov rsi, prompt_msg  ; rsi <- prompt_msg
    mov edx, 18          ; edx <- 18 characters
    syscall              
    ret

print:
    mov eax, 1           ; eax <- write()
    mov edi, 1           ; edi <- 1 (stdout)
    mov rsi, msg         ; rsi <- message
    mov edx, 12          ; edx <- 12 characters
    syscall              
    ret

printoutput:
    sub rax, 10
    mov rdx, rax
    mov rax, 1
    mov rdi, 1
    mov rsi, buffer
    syscall
    ret

exit:
    mov eax, 60          ; eax <- exit()
    mov edi, 0           ; edi <- exit-code 0
    syscall              
    ret