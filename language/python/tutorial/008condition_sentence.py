#!/usr/bin/env python
# coding=utf-8


'''
1、if语句：
if_stmt ::= "if" expression ":" suite
			( "elif" expression ":" suite )*
			["else" ":" suite]
'''

v1 = 1
v2 = 2

if v1 == 1 :
	if v2 == 2:
		print("v2 is ", 2)
	else:
		print("v2 is not ", 2)
else:
	print("v1 is not ", 1)


'''
2、while语句：
while_stmt ::= "while" expression ":" suite
				["else" ":" suite]
'''

v3 = 5
while v3 > 0:
	print("v3 is ", v3)
	v3 -= 1
else:
	print("else v3 is", v3)