BITS 32

SECTION .data
age: db 0x56
age2: db 0x57

SECTION .text
mov ebx, [age]
mov eax, [age2]