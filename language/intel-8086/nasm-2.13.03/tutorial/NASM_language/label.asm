SECTION .data

;aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
;[2.13-3.1]labels中的有效的字符是字母，数字，'_'，'$'，'#'，'@'，'~'，'.'和'?'。但只
;有字母'.',(具有特殊含义，参阅2.13-3.9),'_'和'?'可以作为标识符的开头。
;
;定义标识符时，后面可以跟一个冒号，也可以不跟，建议使用冒号形式。
;使用标识符时，标识符前面可以带一个美元符号，也可以不带，建议使用美元符号形式。



data_section_begin: db 0x88,0x88,0x88,0x88
data1 db 0x56
data2: db 0x57


BITS 32
SECTION .text
mov eax, [data1]
mov ebx, [$data2]

;ndisasm -b32 label 结果
;00000000  A110000000        mov eax,[0x10]
;00000005  8B1D11000000      mov ebx,[dword 0x11]
;0000000B  008888888856      add [eax+0x56888888],cl
;00000011  57                push edi