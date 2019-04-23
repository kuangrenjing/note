#!/usr/bin/python
# -*- coding: UTF-8 -*-


#迭代

#aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#Python频繁地使用迭代器。它允许在数据结构长度未知和具体实现未知的情况下遍历整个数据结构。

#在python中，列表、字符串、元组、字典、集合等都是可迭代的对象。元组或列表在一次迭代产生一
#项，而字符串一次迭代会产生一个字符，字典一次迭代返回字典中的一个键。

person_info = {"name":"CFQ","age":30,"height":1.68}
for info in person_info:
	print(person_info, "'s info is:", info)

for info_value in person_info.values():
	print(person_info, "'s info_value is:", info_value)


#字符串
word = 'cat'
for letter in word:
	print(word, "'s letter is:", letter)