SECTION .data

;aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
;[2.13-3.2.1]labels中的有效的字符是字母，数字，'_'，'$'，'#'，'@'，'~'，'.'和'?'。
;但只有字母'.',(具有特殊含义，参阅2.13-3.9),'_'和'?'可以作为标识符的开头。
;
;定义标识符时，后面可以跟一个冒号，也可以不跟，建议使用冒号形式。
;使用标识符时，标识符前面可以带一个美元符号，也可以不带，建议使用美元符号形式。



data_section_begin: db 0x88,0x88,0x88,0x88
datab: db 0x56
dataw: dw 0x57
datad: dd 0x58


;BITS 32
SECTION .text
mov ax, [0x1]
mov bx, [0x1]

;ndisasm -b32 label 结果