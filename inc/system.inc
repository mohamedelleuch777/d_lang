

;####################################################################################
;####################################################################################
;#################################  PROGRAM START  ##################################
;####################################################################################
;####################################################################################

%macro PROGRAM_START 0



    %ifidn __OUTPUT_FORMAT__, win64
        section   .text
        global    entryAsm
        entryAsm:
    %elifidn __OUTPUT_FORMAT__, elf64
        section   .text
        global    entryAsm
        entryAsm:   
    %elifidn __OUTPUT_FORMAT__, macho64
        section .text
    global _main
        ;global main ; for macos
        
    _main:
        ; C equivalent: function declaration and opening curley bracket
        ; of the beginning of the function:
        ; void main () {
        push    rbp         ; set up stack frame
                            ; here we are saving the _main base pointer
        mov     rbp, rsp    ; creating a new base stack by moving the 
                            ; stack pointer inside it
    %endif

%endmacro

;####################################################################################
;####################################################################################
;##################################  PROGRAM END  ###################################
;####################################################################################
;####################################################################################

%macro PROGRAM_END 1

    %ifidn __OUTPUT_FORMAT__, win64
        exit %1
    %elifidn __OUTPUT_FORMAT__, elf64
        exit %1
    %elifidn __OUTPUT_FORMAT__, macho64
        ; C equivalent: closing curley bracket of ending function 
        ; }
        mov     rsp, rbp    ; restore main function pointer into the base pointer
        pop     rbp
    
        exit %1
    %endif

%endmacro


;####################################################################################
;####################################################################################
;#################################  PROGRAM EXIT  ###################################
;####################################################################################
;####################################################################################

%macro exit 1
    mov rax, SYS_EXIT
    mov rdi, %1
    syscall
%endmacro


