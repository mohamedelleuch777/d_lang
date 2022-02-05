%ifidn __OUTPUT_FORMAT__, win64

%elifidn __OUTPUT_FORMAT__, elf64
    %include "../inc/xilyor.inc"
%elifidn __OUTPUT_FORMAT__, macho64
    %include "xilyor.inc"
%endif

extern _SDL_Init
extern _mySDL_Init
extern _write

section .data

    text db "Hello, World! hahaha", 10, 0
    format db "%s", 0


section .bss


;RDI, RSI, RDX, RCX, R8, and R9 for the first 6 arguments
    
 PROGRAM_START
    


    
    ; printf
    mov     qword rdi, format
    mov     qword rsi, text
    call    _write


push 0xFFFF
mov rdi, 0xFFFF
call _SDL_Init
    
    ; printf
    mov     qword rdi, format
    mov     qword rsi, text
    call    c_printf



PROGRAM_END 0
    
