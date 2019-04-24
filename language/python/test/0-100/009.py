#!/usr/bin/python
# -*- coding: UTF-8 -*-

#函数的使用


def commentary(color):
	if color == 'red':
		return "It's a tomato."
	elif color == "green":
		return "It's a green pepper."
	elif color == 'bee purple':
		return "I don't know what it is, but only bees can see it."
	else:
		return "I've never heard of the color " + color + "."

print(type(commentary))
print(commentary('blue'))

#*收集位置参数 元组
def print_args(*arg):
	print("call print_args with a tuple args:", arg)

print_args(1, 2)

#**收集关键字参数 字典
def print_kwargs(**kwargs):
	print("call print_kwargs function with a dict args:", kwargs)

print_kwargs(a=1, b=2)

def deal_kwargs(**kwargs):
	len1 = len(kwargs)
	if len1 == 1:
		print("a = ", kwargs['a'])
	elif len1 == 2:
		print("a = ", kwargs['a'], "b = ", kwargs['b'])

deal_kwargs(a = 1, b = 2)


#如果要混用*args **kwargs参数，*args参数需在前，调用时位置参数也需在前
def print_kwargs2(*args, **kwargs):
	print("call print_kwargs2 function with a dict args:", args)
	print("call print_kwargs2 function with a dict args:", kwargs)

print_kwargs2(1, b = 2, c = 3)


#document string
def print_if_true(thing, check):
	'''
	Prints the first argument if a second argument is true.
	The operation is:
			1. Check whether the *second* argument is true.
			2. If it is, print the *first* argument.
	'''
	if check:
		print(thing)

help(print_if_true)

print("print_if_true's document string is \r\n <", print_if_true.__doc__, "\r\n>")


#closure闭包
def knights2(saying):
	def inner2():
		return "We are the knights who say: '%s'" % saying
	return inner2

a = knights2("mqs")
b = knights2("cfq")

print(a())
print(b())


#lambda()函数
def edit_story(words, func):
	for word in words:
		print(func(word))

fruit = ("apple", "banana", "orange")

edit_story(fruit, lambda word: word.capitalize() + '!')

#decorator 修饰器
def document_it(func):
	def new_function(*args, **kwargs):
		print('Running function:', func.__name__)
		print('Positional arguments:', args)
		print('Keyword arguments:', kwargs)
		result = func(*args, **kwargs)
		print('Result:', result)
		return result
	return new_function


@document_it
def add_ints(a, b):
	return a + b

add_ints(3, 5)

add_ints_er = document_it(add_ints)
#add_ints_er(4, 6)


