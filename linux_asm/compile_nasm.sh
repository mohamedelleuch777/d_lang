#nasm -f elf $1.asm #This creates a new hello.o, actually the same :) 
#gcc $1.o -o $1   # this creates a binary hello, use gcc and no ld because of the call of external functions

nasm -f elf64 -o $1.o $1.asm
ld $1.o -o $1