; **Write an ALP program to convert a decimal**
; **number to binary.**

section .text
global _start
_start:
mov eax , 3
mov ebx , 0
mov ecx , number
mov edx , 4
int 0x80
mov edx , number
call str2int
; Loop for implementing the iterative division to obtain remainders
div_loop:
inc dword[len] ; Keep track of word length of binary string
xor edx, edx
mov ecx, 2 ; put denominator in ecx
div ecx ; Divide to get numerator and remainder
push edx
cmp eax , 0 ; Check if the given number has reached zero or not => If yes
exit, else continue
jne div_loop
jmp _print
; Function to print the obtained string in reverse order
_print:
dec dword[len]
pop edx
push eax
mov eax , edx
add eax , 48
push eax
mov eax , esp
mov ecx, eax
mov edx, 1
mov ebx, 1
mov eax, 4
int 0x80
pop eax
pop eax
cmp dword [len], 0
jne _print
mov eax, 1
int 0x80
str2int: ; Converts an string in EDX to a integer stored in eax.
xor eax, eax ;clear off anything in eax
.top:
movzx ecx, byte [edx] ; get each character of string in each iteration
inc edx
cmp ecx, '0' ;If you reach end of string, then you're done.
jb .done
cmp ecx, '9'
ja .done
sub ecx, '0' ;converting character to integer
imul eax, 10 ;multiply the result obtained till now by ten
add eax, ecx ;add in current digit
jmp .top ;loop until done.
.done:
ret
section .data
len db 0
segment .bss
;result resb 1
number resd 4