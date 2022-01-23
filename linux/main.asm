%include "../inc/xilyor.inc"


extern      printf
extern      sayeb

PROGRAM_START
; push    rbp         ; set up stack frame
;                         ; here we are saving the _main base pointer
;     mov     rbp, rsp    ; creating a new base stack by moving the 
;                         ; stack pointer inside it

    mov     qword rdi, format ; arg 1: format => %s %d %i %f ...
    mov     qword rsi, message2 ; arg 2: text
            call        printf

            call        sayeb
            ; write 's', message
            mov       rax, 1                  ; system call for write
            mov       rdi, 1                  ; file handle 1 is stdout
            mov       rsi, message1            ; address of string to output
            mov       rdx, 13                 ; number of bytes
            syscall                           ; invoke operating system to do the write

PROGRAM_END 0

section   .data
message1:  db        "Hello, World", 10, 0      ; note the newline at the end
message2:  db        "This message is written by printf", 10, 0      ; note the newline at the end
format:  db        "%s", 0      ; note the newline at the end