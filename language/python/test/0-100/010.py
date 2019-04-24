#!/usr/bin/python
# -*- coding: UTF-8 -*-

#生成器的使用


def my_range(first=0, last=10, step=1):
	number = first   #局部变量
	while number < last:
		yield number  #yield是关键
		number += step

ranger = my_range(1, 5)
for i in ranger:
	print(i)