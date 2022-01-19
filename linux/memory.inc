;INPUTS:
; ecx: length of allocated memory
;RESULT:
; return in rax a pointer to the allocated memory

%macro malloc 2
    mov eax, 192    ; mmap2
    xor ebx, ebx    ; addr = NULL
    ;mov ecx, 4096   ; len = 4096
    ;pop rcx         ; length of allocated memory
    mov rcx, %2
    mov edx, $7     ; prot = PROT_READ|PROT_WRITE|PROT_EXEC
    mov esi, $22    ; flags = MAP_PRIVATE|MAP_ANONYMOUS
    mov edi, -1     ; fd = -1
    xor ebp, ebp    ; offset = 0 (4096*0)
    int $80         ; make call
    mov qword [%1], rax ; get ptr from rax to variable
%endmacro
