%ifidn __OUTPUT_FORMAT__, win64

%elifidn __OUTPUT_FORMAT__, elf64
    %include "../inc/xilyor.inc"
%elifidn __OUTPUT_FORMAT__, macho64
    %include "xilyor.inc"
%endif

;extern _mySDL_Init

section .data



section .bss


;RDI, RSI, RDX, RCX, R8, and R9 for the first 6 arguments
    
 PROGRAM_START
    

push 0x20
;call _mySDL_Init
    



PROGRAM_END 0
    
