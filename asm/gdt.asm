;
; https://github.com/dipolukarov/osdev/blob/master/gdt.s
;

[GLOBAL jump_gdt]		; Allows the C code to call gdt_flush().
jump_gdt:

	jmp	0x08:.flush	; 0x08 is the offset to our code segment: Far jump!
.flush:
	ret

[GLOBAL idt_flush]		; Allows the C code to call idt_flush().
idt_flush:
	mov	eax, [esp+4]	; Get the pointer to the IDT, passed as a parameter.
	lidt	[eax]		; Load the IDT pointer.
	ret