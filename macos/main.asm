%include "constants.asm"
%include "system.inc"



section .data
    text db "Hello, World! hahaha", 10, 0
    stringPtr dq 0 ; 64bit size pointer
    ; var int_1 integer
    int_1 dq 48
    CR db 10, 0
    
    %ifidn __OUTPUT_FORMAT__, win64
        text1 db "a message from windows.", 10
    %elifidn __OUTPUT_FORMAT__, elf64
        text1 db "a message from linux.", 10
    %elifidn __OUTPUT_FORMAT__, macho64
        text1 db "a message from macos.", 10
    %endif
    ;text1 db __OUTPUT_FORMAT__


section .text
    global _main
    global _start
 
_main:

    mov     rax, SYS_WRITE
    mov     rdi, STDOUT
    mov     rsi, text1
    mov     rdx, 22
    syscall
 
    ;exit 0

    mov rax, SYS_EXIT
    mov rdi, 0
    syscall
