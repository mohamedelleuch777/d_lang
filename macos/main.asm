%include "xilyor.inc"

extern _printf
extern _malloc


section .data
    msg db "this message is from asm", 10, 0
    text db "Hello, World! hahaha", 10, 0
    joke db "nesi l bera7 wommelih", 10, 0
    num dd 1234567890
    format db "%s", 0
    stringPtr dq 0 ; 64bit size pointer
    ; var int_1 integer
    int_1 dq 48
    CR db 10, 0


section .bss
    testPtr resq 1

;RDI, RSI, RDX, RCX, R8, and R9 for the first 6 arguments
    
 PROGRAM_START
    
    write format, text
    ;malloc testPtr, 4096
    mov     qword rdi, 4096
    call    _malloc
    mov     [rel testPtr], rax
    read testPtr, 4096
    write format, testPtr
    mov     qword rdi, format
    mov     qword rsi, joke
    call _printf




PROGRAM_END 0
    
