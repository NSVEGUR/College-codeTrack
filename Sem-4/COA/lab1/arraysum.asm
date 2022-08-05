; Choose a positive value 5 ≤ P ≤ 20, 
; write ALP by defining a P-element array containing 
; P random values and do the sum of these values in the array 
; and display the result as the output.

section .data
	
    global arr
	
    len db 9
	
    msg db "Array Sum : "
	mlen equ $ - msg

      msg1 db " ", 0xA
  len1 equ $- msg1

arr:				
	dd 50
	dd 65
	dd 15
	dd 33
	dd 35
	dd 75
	dd 57
	dd 99
	dd 87


section .text
	
    global _start

_start:

	mov   eax,4
	mov   ebx,1
	mov   ecx, msg
 	mov   edx, mlen
	int   0x80

	
	mov esi, 9	
	xor eax, eax	

sum_it:
	mov ebx,DWORD [arr+esi*4-4] 
	add eax, ebx	
	dec esi			
	test esi, esi
	jnz sum_it		

    mov edi, sum                
    call int_to_str                
    sub edi, sum                
    mov [sum_len], edi
    
    mov eax, 4
    mov ebx, 1
    mov ecx, sum
    mov edx, [sum_len]
    int 0x80  

    mov ecx, msg1
  mov edx, len1
  mov ebx, 1
  mov eax, 4
  int 0x80

	; gracefull exit
	mov eax, 1
	mov ebx, 0
	int 0x80 

int_to_str:
    ; Converts an positive integer in EAX to a string pointed to by EDI
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
    ret   
    
section .bss
    
    sum resb 40                 
    sum_len resd 1