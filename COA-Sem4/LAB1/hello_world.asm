section .text
global _start
_start:

mov edx,len1
mov ecx, msg1
mov ebx, 1
mov eax, 4
int 0x80
mov eax, 1
Mov  ebx,0
int 0x80

mov edx,len2
mov ecx, msg2
mov ebx, 1
mov eax, 4
int 0x80
mov eax, 1
Mov  ebx,0
int 0x80

mov edx,len3
mov ecx, msg3
mov ebx, 1
mov eax, 4
int 0x80
mov eax, 1
Mov  ebx,0
int 0x80

mov edx,len4
mov ecx, msg4
mov ebx, 1
mov eax, 4
int 0x80
mov eax, 1
Mov  ebx,0
int 0x80


section .data
msg1 db "The Netwide Assembler is "
msg2 db " designed for portability and modularity.", 0xa
msg3 db "An assembler tran"
msg4 db "slates assembly code into machine code."
len1 equ $ - msg1
len2 equ $ - msg2
len3 equ $ - msg3
len4 equ $ - msg4