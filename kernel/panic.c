//
// Created by khhs on 2022-04-14.
//

#include "panic.h"
#include "util.h"

void kpanic(char* err, int code){
    clear();
    print("KERNEL PANIC\n");
    print("THE KERNEL THREW A CRITICAL ERROR: \"");
    print(err);
    char s[256];
    int_to_ascii(code, s);
    print("\" CODE: ");
    print(s);
}

