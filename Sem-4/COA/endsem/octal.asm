section	.text
	global _start       ;must be declared for using gcc
_start:                     ;tell linker entry point
	mov	edx, len    ;message length
	mov	ecx, msg    ;message to write
	mov	ebx, 1	    ;file descriptor (stdout)
	mov	eax, 4	    ;system call number (sys_write)
	int	0x80        ;call kernel
	
	mov eax, [num]  ;mov value in num to eax
	mov edi, res    ;set destination index to res
	call dec2octal  ;calling dec2octal
	sub edi, res    ;subtracting res from edi to get res length
	mov [reslen], edi   ;mov value in edi to reslen
	
	mov	edx, [reslen]    ;result length
	mov	ecx, res    ;result to write
	mov	ebx, 1	    ;file descriptor (stdout)
	mov	eax, 4	    ;system call number (sys_write)
	int	0x80        ;call kernel
	jmp exit        ;jmp to exit

dec2octal:
    xor ecx, ecx  ;cleaning ecx
    mov ebx, 8    ; since octal means 8
.LL1:
    xor edx, edx  ;cleaning edx
    div ebx    ; eax/ebx => reminder -> edx, quotient -> eax
    push dx     ; push dx to stack (reminder)
    inc ecx     ;incrementing counter register
    test eax, eax   ;testing if quotiend eax is zero
    jnz .LL1    ;run .LL1 again if jnz is not zero
.LL2:
    pop dx      ;pop from stack to dx
    or dl, '0'  ;converting to ascii
    mov [edi], dl   ;moving answer to destination index
    inc edi     ;increment destination index
    loop .LL2   ;llop .LL2 until ecx = 0
mov byte [edi], 0 ;for termination
ret ;return from the procedure
    
exit:
	mov	eax, 1	    ;system call number (sys_exit)
	int	0x80        ;call kernel

section	.data

msg	db	'Octal form of 16 is ',0xa	;our dear string
len	equ	$ - msg			;length of our dear string
num dd 16

section .bss
res resd 20         ;for result
reslen resd 5       ;for length of the result