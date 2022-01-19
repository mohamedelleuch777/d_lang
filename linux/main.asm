%include "xilyor.inc"

section .data
    text db "Hello, World! hahaha", 10, 0
    stringPtr dq 0 ; 64bit size pointer
    ; var int_1 integer
    int_1 dq 48
    CR db 10, 0

section .text
    global _main
    global _start
 
_main:
_start:
    ; print text
    ; malloc stringPtr, 100
    ; input stringPtr, 50
    ; print stringPtr

    print 's',text
    ;print 's', CR
    input int_1, 1
    ;sub byte [int_1], 17
    print 'i', int_1 
    print 's', CR
 
    exit 0
    
