#!/usr/bin/env python
# coding=utf-8

'''
1、python内建函数在线文档：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	https://docs.python.org/3/library/functions.html
'''

'''
2、交互式函数帮助信息：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	可以在交互式命令行通过help(函数名)查看函数的帮助信息。
'''

'''
3、函数定义：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	在Python中，定义一个函数要使用def语句，依次写出函数名、括号、括号中的参数和冒号:，
然后，在缩进块中编写函数体，函数的返回值用return语句返回。
'''

def my_abs(x):
	if x >= 0:
		return x
	else:
		return -x

'''
4、函数调用：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	Python内置了很多有用的函数，我们可以直接调用。要调用一个函数，需要知道函数的名称和
参数，调用格式：函数名(参数1, 参数2, ...)

	调用函数的时候，如果传入的参数类型或数量不对，会报TypeError的错误。
'''
