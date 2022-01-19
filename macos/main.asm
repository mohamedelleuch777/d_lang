%include "system.inc"

; %ifidn __OUTPUT_FORMAT__, win32 
;     %define NEWLINE 65 
; %elif __OUTPUT_FORMAT__, elf32 
;     %define NEWLINE 66 
; %endif

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

    mov     rax, 0x2000004
    mov     rdi, 1
    mov     rsi, text
    mov     rdx, 21
    syscall
 
    ;exit 0

    mov rax, 0x2000001
    mov rdi, 0
    syscall
