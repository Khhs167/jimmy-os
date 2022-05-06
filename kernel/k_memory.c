//
// Created by khhs on 2022-04-19.
//

#include "kernel/k_memory.h"

void* memset(void* ptr, int value, int num){
    unsigned char* ptr_byte = (unsigned char*)ptr;

    for (int i = 0; i < num; ptr_byte[i] = (unsigned char)value, i++);
    return ptr;
}