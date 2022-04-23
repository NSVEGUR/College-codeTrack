
; Choose five numbers between 100 and 999. 
; Write ALP by using conditional instructions for finding 
; the largest of these five numbers and display the result as the output.

section	.text
   global _start         ;must be declared for using gcc

_start:	                 ;tell linker entry point
   mov   eax, [num1]
   cmp   eax, [num2]
   jg    next1
   mov   eax, [num2]
   
	next1:

   cmp   eax, [num3]
   jg    next2
   mov   eax, [num3]
   
	next2:
	
   cmp   eax, [num4]
   jg    next3
   mov   eax, [num4]
   
	next3:
	
    cmp   eax, [num5]
   jg    finish
   mov   eax, [num5]
   
	finish:
	
	mov edi,res
	call int2str
	sub edi,res
	mov [len],edi
   
   mov   ecx,res
   mov   edx, [len]
   mov   ebx,1	;file descriptor (stdout)
   mov   eax,4	;system call number (sys_write)
   int   0x80	;call kernel
    
   mov   eax, 1
   int   80h
   
int2str:    ; Converts an positive integer in EAX to a string pointed to by EDI
    xor ecx, ecx
    mov ebx, 10
    
    .LL1:                   ; First loop: Save the remainders
    xor edx, edx            ; Clear EDX for div
    div ebx                 ; EDX:EAX/EBX -> EAX Remainder EDX
    push dx                 ; Save remainder
    inc ecx                 ; Increment push counter
    test eax, eax           ; Anything left to divide?
    jnz .LL1                ; Yes: loop once more
.LL2:                   ; Second loop: Retrieve the remainders
    pop dx                  ; In DL is the value
    or dl, '0'              ; To ASCII
    mov [edi], dl           ; Save it to the string
    inc edi                 ; Increment the pointer to the string
    loop .LL2               ; Loop ECX times

    mov byte [edi], 0       ; Termination character
    ret                     ; RET: EDI points to the terminating NULL

section	.data
   
   num1 dd 101
   num2 dd 201
   num3 dd 301
   num4 dd 505
   num5 dd 704

segment .bss
   res resd 20
   len resd 5