;
; https://github.com/dipolukarov/osdev/blob/master/gdt.s
;

[global gdt_flush]	; Allows the C code to link to this
[extern gdt_pointer]		; Says that '_gp' is in another file
[extern gdt]
[extern gdt_code]

gdt_flush:
	lgdt [gdt_pointer]	; Load the GDT with our '_gp' which is a special pointer
	jmp 0x08:flush2	; 0x08 is the offset to our code segment: Far jump!
	;mov ax, 0x10	; 0x10 is the offset in the GDT to our data segment
	;mov ds, ax
	;mov es, ax
	;mov fs, ax
	;mov gs, ax
	;mov ss, ax
flush2:
	ret		; Returns back to the C code!