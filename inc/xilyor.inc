%ifidn __OUTPUT_FORMAT__, win64
    %include "constants.inc"
    %include "stdio.inc"
    %include "memory.inc"
    %include "system.inc"
    %include "lib_c_windows.inc"
%elifidn __OUTPUT_FORMAT__, elf64
    %include "../inc/constants.inc"
    %include "../inc/stdio.inc"
    %include "../inc/memory.inc"
    %include "../inc/system.inc"
    %include "../inc/lib_c_linux.inc"
%elifidn __OUTPUT_FORMAT__, macho64
    %include "constants.inc"
    %include "stdio.inc"
    %include "memory.inc"
    %include "system.inc"
    %include "lib_c_macos.inc"
%endif


