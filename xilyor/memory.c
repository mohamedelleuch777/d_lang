#include <stdlib.h>
#include <string.h>

void* memAlloc(size_t memSize) {
    return malloc(memSize);
}


void memCopy(char* dst, char* src , size_t memSize) {
    //memcpy(dst,src,memSize);
    while(memSize) {
		*dst = *src;
		dst += 1;
		src += 1;
		memSize -= 1;
	}
}

void memInit(char* memPtr, char c, size_t memSize) {
    //memcpy(dst,src,memSize);
    while(memSize) {
		*memPtr = c;
		memPtr += 1;
		memSize -= 1;
	}
}

