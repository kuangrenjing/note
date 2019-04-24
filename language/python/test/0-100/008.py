#!/usr/bin/python
# -*- coding: UTF-8 -*-

#推导式的使用


#列表推导式：
#	[ expression for item in iterable ]
#	[expression for item in iterable if condition]
#	[(row, col) for row in rows for col in cols]
print("---list comprehensions test---")
list1 = [i*2 for i in range(1,6)]
print("[i*2 for i in range(1,6)] will create a list: <", list1, ">")

list1 = [i*2 for i in range(1,6) if i % 2 == 0]
print("[i*2 for i in range(1,6) if i % 2 == 0] will create a list: <", list1, ">")
print("\r\n")




#字典推导式{key_expression : value_expression for expression in iterable}
print("---dict comprehensions test---")
word = 'letters'
letter_counts = {letter: word.count(letter) for letter in word if letter > 'e'}
print("{letter: word.count(letter) for letter in word if letter > 'e'} will create a dict:<", letter_counts, ">")
print("\r\n")

#集合推导式 {expression for expression in iterable }