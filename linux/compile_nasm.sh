
FILE_NAME=$1
PATH=$2
OS_NAME=$3
NASM=$4
LD=$5

FULL_PATH=${PATH}/${FILE_NAME}
XILYOR_OBJ=${PATH}/xilyor/linux.o

println() {
    MSG=$1
    printf '\e[1;34m%-6s\e[m%s\n'  ${MSG}
}

print() {
    MSG=$1
    printf '\e[1;34m%-6s\e[m'  ${MSG}
}

$NASM -felf64 ${FULL_PATH}.asm
echo "compilation finished"
$LD ${FULL_PATH}.o ${XILYOR_OBJ} -lc -o ${FULL_PATH} -entry main
echo "linking finished"
#$LD ${FILE_NAME}.o -lc -o ${FILE_NAME} -entry main