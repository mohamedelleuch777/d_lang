
extern _memAlloc
extern _memCopy
extern _memInit


;####################################################################################
;####################################################################################
;###################################### MALLOC ######################################
;####################################################################################
;####################################################################################

; params:
;   malloc returnedPtr, size
%macro malloc2 2
    mov     rdi, %2 ; variable size (memory length to allocate)
    call    _memAlloc
    mov     [rel %1], rax
%endmacro

;####################################################################################
;####################################################################################
;###################################### MEMCPY ######################################
;####################################################################################
;####################################################################################

; params:
;   memcpy ptrDst, ptrSrc, size
%macro memcpy 3
    mov     rdi, %1 ; ptr to the destination
    mov     rsi, %2 ; ptr to the source
    mov     rdx, %3 ; size of copied block
    call    _memCopy
%endmacro

;####################################################################################
;####################################################################################
;################################### MEM_RESET ######################################
;####################################################################################
;####################################################################################

; params:
;   memset memPtr, char, size
%macro memset 3
    mov     rdi, %1 ; ptr to the destination
    mov     rsi, %2 ; char to set the memory with it
    mov     rdx, %3 ; size of the affected block
    call    _memInit
%endmacro

















;INPUTS:
; ecx: length of allocated memory
;RESULT:
; return in rax a pointer to the allocated memory

%macro mallocASM 2
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

