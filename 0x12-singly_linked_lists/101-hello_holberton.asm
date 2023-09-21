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
    mov rax, 0      ; Clear RAX register
    call printf     ; Call printf
    pop rbp
    ret

