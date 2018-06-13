#!/usr/bin/env bash

<<COMMENT
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
资料：
	https://wenku.baidu.com/view/77c60ac2d4bbfd0a79563c1ec5da50e2524dd153.html
COMMENT


<<COMMENT
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
grub官网：http://www.gnu.org/software/grub/

查看本机grub版本：rpm -qa|grep "grub"

/boot/grub2/i386-pc/boot.img
/boot/grub2/i386-pc/core.img
	boot.img固定为512Byte、core.img小于32KByte。它们可以通过grub2-install命令安装到
硬盘上相应位置。

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
COMMENT