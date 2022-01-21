#include <stdio.h>

void write(const char* format, char* str) {
    printf(format, str);
}

int read(char* str, int length) {
    if( fgets(str, length, stdin) == NULL) {
        return 0;
    }
    return 1;
}