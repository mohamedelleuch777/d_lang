%ifidn __OUTPUT_FORMAT__, win64

%elifidn __OUTPUT_FORMAT__, elf64
    %include "../inc/xilyor.inc"
%elifidn __OUTPUT_FORMAT__, macho64
    %include "xilyor.inc"
%endif



section .data

    window_title        db "Hello, World! hahaha", 10, 0
    err1                db "Cannot initialize the Framework", 10, 0
    err2                db "Sdl was initialized but it couldn't create a window", 10, 0
    format              db "%s", 0

    isRunning           dq 0x1

section .bss
screen              resq        1 ; screen pointer 1 qword
SDL_Event           resb        56

;RDI, RSI, RDX, RCX, R8, and R9 for the first 6 arguments
    
 PROGRAM_START
    

    ;push 0x00000020
    mov rdi, 0x00000020
    call SDL_Init
    cmp rax, 0
    jge  sdl_was_initialized
    
    ; printf
    mov     qword rdi, format
    mov     qword rsi, err1
    call    c_printf
    PROGRAM_END 1 ; exit with error code 1

    sdl_was_initialized:

    mov rdi, window_title
    mov rsi, 0x1FFF0000 ; SDL_WINDOWPOS_UNDEFINED
    mov rdx, 0x1FFF0000 ; SDL_WINDOWPOS_UNDEFINED
    mov rcx, 640
    mov r8, 480
    mov r9, 0x00000002 ; SDL_WINDOW_OPENGL
    call SDL_CreateWindow
    mov [rel screen], rax
    cmp rax, 0
    jne  window_was_created
    
    ; printf
    mov     qword rdi, format
    mov     qword rsi, err2
    call    c_printf
    call    SDL_Quit
    PROGRAM_END 2 ; exit with error code 2

    window_was_created:

    while:
    cmp qword [rel isRunning], 0
    je  exit_program

    call SDL_PollEvent
    mov [rel SDL_Event], rax




    jmp while

    exit_program:
call    SDL_Quit
PROGRAM_END 0
    
