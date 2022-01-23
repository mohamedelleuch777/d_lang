


extern _writeStr
extern _writeInt
extern _writeFloat
extern _read


;####################################################################################
;####################################################################################
;######################################## WRITE #####################################
;####################################################################################
;####################################################################################

; params:
;   write varFormat, string
;INPUTS:
; @param: string variable 
;RESULT:
; print string to stdio
%macro write 2
    mov al, %1
    ; ##### case 's':

    cmp al, 's'
    jne %%_skip_string
    mov byte [rel else], 0xFF
    write_string %2
    %%_skip_string:

    ; ##### case 'i':
    cmp al, 'i'
    jne %%_skip_integer
    mov byte [rel else], 0xFF
    write_integer %2
    %%_skip_integer:

    ; ##### case 'f':
    cmp al, 'f'
    jne %%_skip_float
    mov byte [rel else], 0xFF
    write_float %2
    %%_skip_float:

    ; ##### case 'a':
    cmp al, 'a'
    jne %%_skip_address
    mov byte [rel else], 0xFF
    write_integer %2
    %%_skip_address:

    ; ##### else:
    cmp byte [rel else], 0xFF
    je %%_skip_else
    write_string error1
    %%_skip_else:
    mov byte [rel else], 0x00
    
%endmacro


;####################################################################################
;####################################################################################
;######################################## WRITE #####################################
;####################################################################################
;####################################################################################

; params:
;   write varFormat, string
;INPUTS:
; @param: string variable 
;RESULT:
; print string to stdio
%macro writeln 2
    write %1, %2
    write 's', varCr 
%endmacro



%macro write_string 1
    mov     qword rdi, %1 ; arg 1: format => %s %d %i %f ...
    call    _writeStr
%endmacro

%macro write_integer 1
    mov     qword rdi, %1 ; arg 1: format => %s %d %i %f ...
    call    _writeInt
%endmacro

%macro write_float 1
    mov     qword rdi, %1 ; arg 1: format => %s %d %i %f ...
    call    _writeFloat
%endmacro



;####################################################################################
;####################################################################################
;######################################## READ #####################################
;####################################################################################
;####################################################################################

; params:
;   read stringPtr, sizeBuffer
%macro read 2
    mov     qword rdi, %1
    mov     qword rsi, %2 ; buffer size
    call    _read
%endmacro

















;INPUTS:
; @param1: variable to write read in it
; @param1: length of read data
;RESULT:
; input string from stdio
%macro input 2
    mov rax, %1
    ;INPUTS:
    ; rax as pointer to sring
    ;RESULT:
    ; read string from stdio and put it into rax pointer
    %%_input:
        push rax
        mov rax, 0
        mov rdi, 0
        pop rsi
        mov rdx, %2
        syscall
        mov rax, rsi
        add rax, rdx
        inc rax
        mov qword [rax], 0x00
%endmacro



%macro print_number 1
    mov qword rax, [%1]
    ;INPUTS:
    ; rax as pointer to sring
    ;RESULT:
    ; print string to stdio
    mov rbx, number
    %%_loop:
        xor rdx, rdx
        mov rcx, 10
        div rcx
        ;push rax
        add rdx, 48
        
        mov byte [rbx], dl
        inc rbx
        ;pop rax
        cmp rax, 0
        jne %%_loop

        mov rcx, final_number
    %%_reverse_char_order:
        dec rbx
        mov byte al, [rbx]
        mov byte [rcx], al
        inc rcx
        cmp rbx, number
        jge %%_reverse_char_order
    
        mov rax, final_number
        %%_print:
        push rax
        xor rbx, rbx
        %%_print_loop:
            inc rax
            inc rbx
            mov byte cl, [rax]
            cmp cl, 0
            jne %%_print_loop

        mov rax, 1
        mov rdi, 1
        pop rsi
        mov rdx, rbx
        syscall
    
%endmacro

%macro print_core 1
    ;INPUTS:
    ; rax as pointer to sring
    ;RESULT:
    ; print string to stdio
    mov rax, %1
    %%_print:
        push rax
        xor rbx, rbx
        %%_print_loop:
            inc rax
            inc rbx
            mov byte cl, [rax]
            cmp cl, 0
            jne %%_print_loop

        mov rax, 1
        mov rdi, 1
        pop rsi
        mov rdx, rbx
        syscall
%endmacro






section .bss
    number resb 100
    final_number resb 100
    else resb 1

section .text
    error1 db "first argument passed is an invalid format",10,0
    varCr  db CR, 0

