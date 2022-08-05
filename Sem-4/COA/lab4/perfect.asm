; **Write an ALP to check if the given number is a**
    
;     **Perfect number or not.**

section .data
msg1 db " is a Perfect number"
len1 equ $- msg1
msg2 db " is not a Perfect number"
len2 equ $- msg2
num dd 153
section .bss
res resb 10
res_len resb 10
section .text
global _start ;must be declared for using gcc
_start: ;tell linker entry point
mov eax,[num]
mov ebx,2
mov ecx,1
mov edx,0
perfect_Num : ;To find the sum of the positive divisors
cmp eax,1
je print
cmp ebx,eax
je print
push eax
push edx
div ebx
cmp edx,0
je sum
end:
pop edx
pop eax
inc ebx
jmp perfect_Num
print:
push eax
push ecx
; Convert the number to a string
mov edi, res ; Argument: Address of the target string
call intTOstr ; Get the digits of EAX and store it as ASCII
sub edi, res ; getting length of the string
mov [res_len], edi
mov ebx,1 ;file descriptor (stdout)
mov eax,4 ;system call number (sys_write)
mov ecx,res
mov edx, [res_len]
int 0x80 ;call kernel
pop ecx
pop eax
cmp eax,1
je print2
cmp ecx,eax
je print1
print2:
mov ebx,1 ;file descriptor (stdout)
mov eax,4 ;system call number (sys_write)
mov ecx,msg2
mov edx, len2
int 0x80 ;call kernel
jmp exit
print1:
mov ebx,1 ;file descriptor (stdout)
mov eax,4 ;system call number (sys_write)
mov ecx,msg1
mov edx, len1
int 0x80 ;call kernel
exit:
mov eax, 1
mov ebx,0
int 80h
sum:
add ecx,ebx
jmp end
intTOstr: ; Converts an positive integer in EAX to a string pointed to by EDI
xor ecx, ecx
mov ebx, 10
_Loop1: ; First loop: Save the remainders
xor edx, edx ; Clear EDX for div
div ebx ; EDX:EAX/EBX -> EAX Remainder EDX
push dx ; Save remainder
inc ecx ; Increment push counter
test eax, eax ; Anything left to divide?
jnz _Loop1 ; Yes: loop once more
_Loop2: ; Second loop: Retrieve the remainders
pop dx ; In DL is the value
or dl, '0' ; To ASCII
mov [edi], dl ; Save it to the string
inc edi ; Increment the pointer to the string
loop _Loop2 ; Loop ECX times
mov byte [edi], 0 ; Termination character
ret ; RET: EDI points to the terminating NULL