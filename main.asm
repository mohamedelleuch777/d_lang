%ifidn __OUTPUT_FORMAT__, win64

%elifidn __OUTPUT_FORMAT__, elf64
    %include "../inc/xilyor.inc"
%elifidn __OUTPUT_FORMAT__, macho64
    %include "xilyor.inc"
%endif

extern printf
extern malloc


section .data
    msg db "this message is from asm", 10, 0
    text db "Hello, World! hahaha", 10, 0
    joke db "nesi l bera7 wommelih", 10, 0
    num dd 1234567890
    format db "%s", 0
    format_scanf db "%s", 0
    stringPtr dq 0 ; 64bit size pointer
    ; var int_1 integer
    int_1 dq 48
    CR db 10, 0


section .bss
    testPtr resq 1
    stdin resq 20
    str1 resq 30

;RDI, RSI, RDX, RCX, R8, and R9 for the first 6 arguments
    
 PROGRAM_START
    
    
    ; printf
    mov     qword rdi, format
    mov     qword rsi, text
    call    c_printf

    ; malloc
    mov     qword rdi, 30
    call    c_malloc
    mov     [rel str1], rax

    ; scanf
    mov     qword rdi, format_scanf
    mov     qword rsi, str1
    call    c_scanf

    ; ; gets
    ; mov     qword rdi, str1
    ; call    c_gets
    
    ; printf
    mov     qword rdi, format
    mov     qword rsi, str1
    call    c_printf
    
    ; printf
    mov     qword rdi, format
    mov     qword rsi, CR
    call    c_printf




PROGRAM_END 0
    
