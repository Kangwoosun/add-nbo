#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "add.h"

int main(int argc, char* argv[]){

    uint32_t a, b;
    size_t result;

    if(argc < 3){
        return -1;
    }

    FILE* first, *second;

    first = fopen(argv[1], "rb");

    if(first == NULL){
        fputs("fopen error", stderr);
        exit(1);
    }

    second = fopen(argv[2], "rb");
    if(second == NULL){
        fputs("fopen error", stderr);
        exit(2);
    }

    result = fread(&a, 1, 4, first);

    if(result != 4){
        fputs("reading error", stderr);
        exit(3);
    }

    result = fread(&b, 1, 4, second);

    if(result != 4){
        fputs("reading error", stderr);
        exit(4);
    }

    a = rev(a);
    b = rev(b);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)", a,a, b,b, add(a,b),add(a,b));

    return 0;

}

/*
$ echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
$ echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
*/