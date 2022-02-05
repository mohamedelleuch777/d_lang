
FILE_NAME=$1
PATH=$2
OS_NAME=$3
NASM=$4
LD=$5

FULL_PATH=${PATH}/${FILE_NAME}
XILYOR_OBJ=${PATH}/xilyor/xilyor.o

println() {
    MSG=$1
    printf '\e[1;34m%-6s\e[m%s\n'  ${MSG}
}

print() {
    MSG=$1
    printf '\e[1;34m%-6s\e[m'  ${MSG}
}

cd ..
$NASM -f macho64 ${FULL_PATH}.asm -i${PATH}/inc
$LD ${FULL_PATH}.o ${XILYOR_OBJ} -o  ${FILE_NAME} -macosx_version_min 11.0 -L /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib -lSystem -no_pie -F/Library/Frameworks -framework SDL2 #-framework Cocoa