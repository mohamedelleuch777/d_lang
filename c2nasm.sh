gcc -fno-asynchronous-unwind-tables -s -c -o $1.o $1.c
objconv -fnasm $1.o   #this creates hello.asm