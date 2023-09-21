section .data
    hello db "Hello, Holberton",0x0A ; The message to be printed (with newline)
    format db "%s",0 ; The format string for printf

section .text
    global main
    extern printf

main:
    push rbp
    mov rdi, format ; Set the format string address
    mov rsi, hello  ; Set the message address
    call printf     ; Call printf
    add rsp, 8      ; Adjust the stack pointer (64-bit)
    pop rbp
    ret

