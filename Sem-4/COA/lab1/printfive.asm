
; Choose a random number 20 ≤ R ≤ 100, 
; write ALP by using loops for printing the 
; numbers (i.e. from 1 to R) and display the result as the output.
section .bss 

res resb 32
reslen resd 2
temp resb 40

section .data

msg db "Printing the result: ",0xA
len equ $-msg

newl db 0xD,0xA
newllen equ $-newl

lim db 35    ; enter your limit here

section .text

    global _start
    
    _start:
    
    mov eax,4
    mov ebx,1
    mov ecx,msg
    mov edx,len
    int 0x80
    
    mov eax,1
    mov [temp],eax
    
    ll_1:
    
    mov edi, res                ; Argument: Address of the target string
    call int2str                ; Get the digits of EAX and store it as ASCII
    sub edi, res                ; EDI (pointer to the terminating NULL) - pointer to sum = length of the string
    mov [reslen], edi
    
    mov eax,4
    mov ebx,1
    mov ecx,res
    mov edx,[reslen]
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,newl
    mov edx,newllen
    int 0x80
    
    mov eax,[temp]
    inc eax
    mov [temp],eax
    
    cmp eax,[lim]
    jg _exit
    
    jmp ll_1
    
    _exit:
    
    
; Exit code
    mov eax, 1
    mov ebx, 0
    int 0x80

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
    
    
; 0xA -> new line
; 0xD -> carriage return