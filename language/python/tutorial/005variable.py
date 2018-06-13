#!/usr/bin/env python
# coding=utf-8

'''
1、变量名
	就是标识符，不需要以美元符号或其它符号开头

2、变量定义
	python的变量在使用之前必须定义，变量只有在赋值以后才会被创建。python中的变量赋值不需要类型声明。
每个变量在内存中创建，都包括变量的标识，名称和数据这些信息。

3、数据类型
	Python有五个标准的数据类型：
		Numbers（数字）
			int（有符号整型）
			long（长整型[也可以代表八进制和十六进制]） 
			float（浮点型） 
			complex（复数） 
		String（字符串）
		List（列表）
		Tuple（元组）
		Dictionary（字典）
'''
string1 = "hello word"
type1 = type(string1)
#type2 = type(type1)
print("string1 is ", string1, "type1 is ", type1, "id(string1) is ", id(string1))
string1 = 10
type1 = type(string1)
print("string1 is ", string1, "type1 is ", type1, "id(string1) is ", id(string1))
string1 -= 1
type1 = type(string1)
print("string1 is ", string1, "type1 is ", type1, "id(string1) is ", id(string1))