#!/usr/bin/env python
# coding=utf-8

'''
文档
	https://docs.python.org/3/reference/toplevel_components.html
'''

'''
1、python解释器输入来源：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	python解释器从若干途径获取它的输入：作为它标准输入的脚本、命令行参数、交互输入、模块
文件。模块文件应该是用的最多的。
'''

'''
2、完整的python程序：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	虽然一个语言的说明书不需要描述语言解释器(interpreter)是如何被调用的，但关注下完整
的python程序包括些什么是非常有用的。一个完整的python程序在最小的初始化环境中运行：所有
的内建和标准模块都是可获取的，但除了sys(变量系统服务)，builtins(内建函数，异常和None)
和__main__，其它的都还没有被引入并初始化。

The interpreter may also be invoked in interactive mode; in this case, it does not 
read and execute a complete program but reads and executes one statement (possibly 
compound) at a time. The initial environment is identical to that of a complete 
program; each statement is executed in the namespace of __main__.

Under Unix, a complete program can be passed to the interpreter in three forms: with 
the -c string command line option, as a file passed as the first command line argument, 
or as standard input. If the file or standard input is a tty device, the interpreter 
enters interactive mode; otherwise, it executes the file as a complete program.
'''