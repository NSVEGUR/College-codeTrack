; Given a positive number, write ALP for verifying 
; whether it is a palindrome number or not, and display the 
; result as the output. (A palindrome number is a number that 
; remains the same when its digits are reversed. For eg: 16461).
section .data
	msg1 db "The given number is palindrome", 0xa
	len1 equ $ - msg1

	msg2 db "The given number is not palindrome", 0xa
	len2 equ $ - msg2

	num dq 16461    
	rev_num dq 0
	digits dq 5     
	it dq 0

section .text
	global _start

_start:
	mov eax, [num]
	xor ecx, ecx

div_loop:
	inc ecx
	mov esi, 10
	xor edx, edx
	idiv esi
	push edx
	cmp eax, 0
	jnz div_loop

	xor edx, edx
	mov esi, 1
	mov ebx, 1
create_rev_number:
	dec ecx
	mov eax, esi
	imul ebx
	mov esi, eax
	mov ebx, 10
	pop eax
	imul esi
	mov edx, [rev_num]
	add edx, eax
	mov [rev_num], edx
	cmp ecx, 0
	jnz create_rev_number

check:
	mov eax, [num]
	cmp eax, edx
	jne negative

affirmitive:
	mov eax, 4
	mov ebx, 1
	mov ecx, msg1
	mov edx, len1
	int 0x80
	jmp exit

negative:
	mov eax, 4
	mov ebx, 1
	mov ecx, msg2
	mov edx, len2
	int 0x80

exit:
	mov eax, 1
	mov ebx, 0
	int 0x80    