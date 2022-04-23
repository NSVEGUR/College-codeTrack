; **Write a program to generate the Fibonacci**
    
;     **series in ALP.**
section .text
global _start
_start:
mov eax , 3
mov ebx , 0
mov ecx , range
mov edx , 3
int 0x80
; Printing the initial message
mov eax , 4
mov ebx , 1
mov ecx , msg1
mov edx , len1
int 0x80
; Printing the 1st number
mov eax , [x]
mov edi, sum
call int2str
sub edi, sum
mov [sum_len], edi
mov eax , 4
mov ebx , 1
mov ecx , sum
mov edx , [sum_len]
int 0x80
mov eax , 4
mov ebx , 1
mov ecx , msg2
mov edx , len2
int 0x80
; Printing the 2nd number
mov eax , [y]
mov edi, sum
call int2str
sub edi, sum
mov [sum_len], edi
mov eax , 4
mov ebx , 1
mov ecx , sum
mov edx , [sum_len]
int 0x80
mov eax , 4
mov ebx , 1
mov ecx , msg2
mov edx , len2
int 0x80
; The Actual program
mov edx, range ; our string
call str2int
mov ecx , eax
sub ecx , 2
fib_loop:
mov [range] , ecx
mov eax , [x]
mov ebx , [y]
add eax , ebx
mov ebx , [y]
mov [x] , ebx
mov [y] , eax
mov edi, sum
call int2str
sub edi, sum
mov [sum_len], edi
mov eax , 4
mov ebx , 1
mov ecx , sum
mov edx , [sum_len]
int 0x80
mov eax , 4
mov ebx , 1
mov ecx , msg2
mov edx , len2
int 0x80
mov ecx , [range]
dec ecx
jne fib_loop
mov eax, 1
int 0x80
str2int: ; Converts an string in EDX to a integer stored in eax.
xor eax, eax ; clear off anything in eax
.top:
movzx ecx, byte [edx] ; get each character of string in each iteration
inc edx
cmp ecx, '0' ; If you reach end of string, then you're done.
jb .done
cmp ecx, '9'
ja .done
sub ecx, '0' ; converting character to integer
imul eax, 10 ; multiply the result obtained till now by ten
add eax, ecx ; add in current digit
jmp .top ; loop until done.
.done:
ret
int2str: ; Converts an positive integer to a string
xor ecx, ecx
mov ebx, 10
.LL1:
xor edx, edx
div ebx
push dx
inc ecx
test eax, eax
jnz .LL1
.LL2:
pop dx
or dl, '0'
mov [edi], dl
inc edi
loop .LL2
mov byte [edi], 0
ret
section .data
x dd 0
y dd 1
;range dd 15
msg1 db "The Fibonacci Sequence is : "
len1 equ $-msg1
msg2 db " "
len2 equ $-msg2
msg3 db "Enter the Range : "
len3 equ $-msg3
segment .bss
sum resb 40
sum_len resd 1
range resb 3