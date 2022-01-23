
FILE_NAME=$1
PATH=$2
OS_NAME=$3
NASM=$4
LD=$5

FULL_PATH=${PATH}/linux/${FILE_NAME}
XILYOR_OBJ=${PATH}/xilyor/linux.o

println() {
    MSG=$1
    printf '\e[1;34m%-6s\e[m%s\n'  ${MSG}
}

print() {
    MSG=$1
    printf '\e[1;34m%-6s\e[m'  ${MSG}
}

 $NASM -felf64 ${FILE_NAME}.asm 
 $LD ${FILE_NAME}.o ${XILYOR_OBJ} -lc -o ${FILE_NAME} -entry main
 #$LD ${FILE_NAME}.o -lc -o ${FILE_NAME} -entry main