//
// Created by khhs on 2022-04-18.
//

#include "cpu/user_mode_inter.h"

extern void jump_usermode(void);

void (*user_mode_callback)();
void on_user_mode_enter(){
    user_mode_callback();
}
void enter_user_mode(void (*pFunction)()){
    user_mode_callback = pFunction;
    jump_usermode();
}