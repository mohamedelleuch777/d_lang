%include "xilyor.inc"


section .data
    msg db "this message is from asm", 10, 0
    text db "Hello, World! hahaha", 10, 0
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
    malloc testPtr, 4096
    read testPtr, 4096
    write format, testPtr


PROGRAM_END 0
    
