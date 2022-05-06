#include "COMPILE_FLAGS.h"
#include "cpu/isr.h"
#include "util.h"
#include "keyboard.h"
#include "keys.h"
#include "panic.h"
#include "cpu/user_mode_inter.h"


unsigned int c_tick = 0;

void timer_callback(uint32_t new_tick){
    c_tick = new_tick;
}

void keyboard_callback(unsigned char scancode){
    /*if(scancode == KEY_ENTER){
        print("ENTER!\n");
    }
    if(KEY_UP(scancode)){
        print("Key up: ");
        print_letter(GET_SCANCODE_UP(scancode));
        putc('\n');
    }*/
    if(!KEY_UP(scancode)) {
        putc(keyboard_char_map[scancode]);
    }
}

void program(){
    return;
}

#include "kernel/k_stdio.h"
#include "cpu/gdt.h"

void main(){
    //isr_install();
    //asm volatile("sti");

    initialize_descriptors();
    //clear();
    //print("BOOTING JIMMOS\n");


    //init_keyboard(keyboard_callback);

    //enter_user_mode(program);
    //return;
}