; Given a positive number, write ALP for 
; verifying whether it is a prime number or 
; not, and display the result as the output.

section .data
	msg1 db "The given number is prime!", 0xa, 0xd
	len1 equ $ - msg1

	msg2 db "The given number is not prime", 0xa, 0xd
	len2 equ $ - msg2

section .text
	global _start

_start:
	mov ecx, 23

	; get esi (num/2)
	mov eax, ecx
	mov bx, 2
	div bx
	mov esi, eax

div_loop:
	mov eax, ecx
	xor edx, edx
	cmp esi, 1
	je verdict_prime
	mov ebx, esi
	div ebx
	dec esi
	cmp edx, 0
	jne div_loop

verdict_not_prime:
	mov eax, 4
    	mov ebx, 1
    	mov ecx, msg2
   	mov edx, len2
    	int 0x80
    	jmp exit

verdict_prime:
    	mov eax, 4
    	mov ebx, 1
    	mov ecx, msg1
    	mov edx, len1
    	int 0x80
    	jmp exit

exit:
	mov eax, 1
	mov ebx, 0
	int 0x80