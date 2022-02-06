#include <stdio.h>

void writeStr(char* str) {
    printf("%s", str);
}

void writeInt(long val) {
    printf("%ld", val);
}

void writeFloat(double val) {
    printf("%+.6f", val);
}

int read(char* str, int length) {
    if( fgets(str, length, stdin) == NULL) {
        return 0;
    }
    return 1;
}

