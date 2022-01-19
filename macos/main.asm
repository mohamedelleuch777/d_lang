%include "xilyor.inc"



section .data
    text db "Hello, World! hahaha", 10, 0
    stringPtr dq 0 ; 64bit size pointer
    ; var int_1 integer
    int_1 dq 48
    CR db 10, 0
    

section .text
    global _main
    global _start
 
_main:

    mov     rax, SYS_WRITE
    mov     rdi, STDOUT
    mov     rsi, text
    mov     rdx, 22
    syscall
 
    exit 0
