//
// Created by khhs on 2022-04-19.
//

/**
 * THIS FILE IS DEPRECATED!
 */


#ifndef JIMMYS_OS_GDT_H
#define JIMMYS_OS_GDT_H

typedef struct {
    unsigned int limit_low              : 16;
    unsigned int base_low               : 24;
    unsigned int accessed               :  1;
    unsigned int read_write             :  1; // readable for code, writable for data
    unsigned int conforming             :  1; // conforming for code, expand down for data
    unsigned int code                   :  1; // 1 for code, 0 for data
    unsigned int code_data_segment      :  1; // should be 1 for everything but TSS and LDT
    unsigned int DPL                    :  2; // privilege level
    unsigned int present                :  1;
    unsigned int limit_high             :  4;
    unsigned int available              :  1; // only used in software; has no effect on hardware
    unsigned int long_mode              :  1;
    unsigned int big                    :  1; // 32-bit opcodes for code, uint32_t stack for data
    unsigned int gran                   :  1; // 1 to use 4k page addressing, 0 for byte addressing
    unsigned int base_high              :  8;
} __attribute__((packed))
gdt_entry_bits;

typedef struct {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed))
gdt_ptr;

gdt_ptr* gdt_pointer;

static gdt_entry_bits gdt[6]; // one null segment, two ring 0 segments, two ring 3 segments, TSS segment

extern void gdt_flush();
void initialize_descriptors();


#endif //JIMMYS_OS_GDT_H
