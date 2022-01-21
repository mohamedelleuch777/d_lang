#!/bin/bash

OS_NAME=""
DIRECTORY=""
FILE_NAME=$1
NASM=$(which nasm)
LD=$(which ld)
MSG1='Starting_the_program...'
MSG2='Program_exited.'
BUILD=$2

println() {
    MSG=$1
    printf '\e[1;34m%-6s\e[m%b\n'  ${MSG}
}

print() {
    MSG=$1
    printf '\e[1;34m%-6s\e[m'  ${MSG}
}

execute() {
    println ${MSG1}
    # sleep 3
    ./${FILE_NAME}
    # sleep 3
    println ${MSG2}
}


compile () {
    path1=$(pwd)
    cd ${DIRECTORY}
    ./compile_nasm.sh ${FILE_NAME} ${path1} ${OS_NAME} ${NASM} ${LD}

    read -p "Do you like to run the compiled program? (y/n)?" choice
    case "$choice" in 
    y|Y ) execute;;
    # n|N ) ls;;
    # * ) echo "invalid";;
    esac
}


compileC () {
    pathC=$(pwd)
    cd xilyor/
    gcc xilyor.c -c
    cd ..
}

# here start script
case "$BUILD" in 
    -b|-B|-build|-BUILD|-Build ) compileC;;
    # n|N ) ls;;
    # * ) echo "invalid";;
esac


if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        OS_NAME="linux"
        DIRECTORY="linux"
elif [[ "$OSTYPE" == "darwin"* ]]; then
        OS_NAME="darwin"
        DIRECTORY="macos"
        compile
else
        OS_NAME="win32"
        DIRECTORY="win32"
fi



