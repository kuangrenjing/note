#!/usr/bin/env python
# coding=utf-8

'''
http://python.usyiyi.cn/documents/python_352/reference/lexical_analysis.html
https://docs.python.org/3/reference/lexical_analysis.html
'''

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、注释：
	python的注释有单行注释和多行注释之分：

	单行注释实例（行内从#符号开始的部分是注释）
		#这是一个单行注释

	多行注释实例(三个单引号开始到三个单引号结束的部分，不管有多少行，或三个双引号开始到
三个双引号结束的部分，不管有多少行)
		\'\'\'
		这是多行注释的第一行
		这是多行注释的第二行
		这是多行注释的第三行
		\'\'\'
	三个单引号还可以用于换行

	python会检查注释的编码，所以即使只在注释中使用中文也需要指定编码。
'''

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
2、指定编码格式的两种格式（https://www.python.org/dev/peps/pep-0263/）：
	# -*- coding: utf-8 -*-
	# coding=utf-8
	需要注意的是，编码格式行与shabang之间不能有空行。
'''

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
3、语句
	python的语句不需要以;结尾，当需要同一行写多条语句时，最后一条语句之前的其它语句需以
;结尾。
'''

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
4、缩进
	其它语言的缩进可能只是为了美观，而python中的缩进是有语法规范的。详见词法分析篇。
'''

