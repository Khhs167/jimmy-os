//
// Created by khhs on 2022-04-19.
//

#include "cpu/gdt.h"
#include "kernel/k_stdio.h"

extern void gdt_flush();

void initialize_descriptors(){

    gdt_pointer->limit = (sizeof(gdt_entry_bits) * 6) - 1;
    gdt_pointer->base = (unsigned int)&gdt;
    gdt_code = gdt[1];

    // (ring 0 segments)
    gdt_entry_bits *ring0_code = &gdt[1];
    gdt_entry_bits *ring0_data = &gdt[2];

    ring0_code->limit_low = 0xFFFF;
    ring0_code->base_low = 0;
    ring0_code->accessed = 0;
    ring0_code->read_write = 0;
    ring0_code->conforming = 0;
    ring0_code->code = 1;
    ring0_code->code_data_segment = 1;
    ring0_code->DPL = 0; // ring 3
    ring0_code->present = 1;
    ring0_code->limit_high = 0xF;
    ring0_code->available = 1;
    ring0_code->long_mode = 0;
    ring0_code->big = 1; // it's 32 bits
    ring0_code->gran = 1; // 4KB page addressing
    ring0_code->base_high = 0;

    *ring0_data = *ring0_data; // contents are similar so save time by copying
    ring0_data->code = 0; // not code but data


    gdt_entry_bits *ring3_code = &gdt[3];
    gdt_entry_bits *ring3_data = &gdt[4];

    ring3_code->limit_low = 0xFFFF;
    ring3_code->base_low = 0;
    ring3_code->accessed = 0;
    ring3_code->read_write = 1; // since this is a code segment, specifies that the segment is readable
    ring3_code->conforming = 0; // does not matter for ring 3 as no lower privilege level exists
    ring3_code->code = 1;
    ring3_code->code_data_segment = 1;
    ring3_code->DPL = 3; // ring 3
    ring3_code->present = 1;
    ring3_code->limit_high = 0xF;
    ring3_code->available = 1;
    ring3_code->long_mode = 0;
    ring3_code->big = 1; // it's 32 bits
    ring3_code->gran = 1; // 4KB page addressing
    ring3_code->base_high = 0;

    *ring3_data = *ring3_code; // contents are similar so save time by copying
    ring3_data->code = 0; // not code but data

    gdt_flush();

    //install_tss(&gdt[5]); // TSS segment will be the fifth

    //flush_tss();
}