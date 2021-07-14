#include "add.h"

uint32_t add(uint32_t a, uint32_t b){
    return a + b;
}

uint32_t rev(uint32_t n){

    uint32_t tmp;

    tmp = (n & 0xff) << 24;
    tmp += (n & 0xff00) << 8;
    tmp += (n & 0xff0000) >> 8;
    tmp += (n & 0xff000000) >> 24;

    return tmp;
}