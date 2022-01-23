%include "xilyor.inc"


section .data
    msg db "this message is from asm", 10, 0
    text db "Hello, World! hahaha", 10, 0
    num dq 1234567890
    stringPtr dq 0 ; 64bit size pointer
    ; var int_1 integer
    int_1 dq 48


section .bss
    testPtr resq 1
    boufa resq 1

;RDI, RSI, RDX, RCX, R8, and R9 for the first 6 arguments
    
 PROGRAM_START
    
    write 's', text
    ;writeln 'i', 67832
    malloc testPtr, 4096
    malloc boufa, 4096
    read num, 4096

    ;memset boufa, 0x0, 4096
    memcpy boufa, num, 3

    ;writeln 'a', num



    ;write stringFormat, text

PROGRAM_END 0
    
