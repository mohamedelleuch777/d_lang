


section .bss
    number resb 100
    final_number resb 100
    else resb 1

section .text
    error1 db "first argument passed is an invalid format",10,0

;INPUTS:
; @param: string variable 
;RESULT:
; print string to stdio
%macro print 2
    mov al, %1
    ; case 's':
    cmp byte al, 's'
    jne %%_skip_string
    mov byte [else], 0xFF
    print_core %2
    %%_skip_string:
    ; case 'i':
    cmp byte al, 'i'
    jne %%_skip_integer
    mov byte [else], 0xFF
    print_number %2
    %%_skip_integer:
    ; else:
    cmp byte [else], 0xFF
    je %%_skip_else
    print_core error1
    %%_skip_else:
    mov byte [else], 0
    
    
    
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
    mov rax, [%1]
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
        mov al, [rbx]
        mov [rcx], al
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
            mov cl, [rax]
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
            mov cl, [rax]
            cmp cl, 0
            jne %%_print_loop

        mov rax, 1
        mov rdi, 1
        pop rsi
        mov rdx, rbx
        syscall
%endmacro