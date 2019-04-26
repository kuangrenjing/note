#!/usr/bin/python
# -*- coding: UTF-8 -*-

#类与对象的使用

#function 与 method的区别测试
class CPerson():
	kind = "black"
	#类函数，实例方法
	def __init__(self, name):
		self.name =name

	#类函数，实例方法
	def print_name(self):
		print(self.name)

	#类函数，实例方法，但只能用类来调用
	def print_hello():
		print("hello every one!")

	#类方法，实例函数
	@classmethod
	def print_kind(cls):
		print(CPerson.kind)

	@staticmethod
	def print_weather():
		print("It's fine today")

person = CPerson('mqs')

def what_type_para(para):
	print("the para type is:", type(para))


print("\r\n类内不用装饰器修饰的函数(print_name)在实例化时会与实例绑定成为实例方法：")
print("	type(CPerson.print_name) is ", type(CPerson.print_name), \
	"type(person.print_name) is ", type(person.print_name))

print("\r\n类内使用@classmethod装饰器修饰的函数(print_kind)与类绑定为类方法，对实例而言是函数")
print("	type(CPerson.print_kind) is ", type(CPerson.print_kind), \
	"type(person.print_kind) is ", type(person.print_kind))

print("\r\n类内用@staticmethod装饰器修饰的函数(print_weather)不与类或实例绑定，对类而言它是函数：")
print("	type(CPerson.print_weather) is ", type(CPerson.print_weather), \
	"type(person.print_weather) is ", type(person.print_weather))

print("\r\n调用方法时会自动把宿主作为第一个参数传入，如果你定义的方法时没有给这个参数留出位\r\n\
置，则把它作为方法调用时会报错或不能满足你的预期，但作为函数调用时则不会")

print("\r\nprint_hello是一个实例方法，但它参数个数不对，所以无法作为方法被调用，但不影响它\r\n\
作为函数被调用，CPerson.print_hello() will return:")
CPerson.print_hello()

print("\r\n正确定义的方法(print_name)，也可以通过显式地传入self的方法来作为函数调用，\r\n\
CPerson.print_name(person) will return:")
CPerson.print_name(person)

from types import MethodType
CPerson.what_type_para = MethodType(what_type_para, CPerson)
person.what_type_para = MethodType(what_type_para, person)

print("\r\npython支持动态绑定（区分通用属性绑定和方法绑定），我们用以下两条语句把\r\n\
what_type_para函数绑定到类和实例")
print("	CPerson.what_type_para = MethodType(what_type_para, CPerson)")
print("	person.what_type_para = MethodType(what_type_para, person)")
print("type(what_type_para) is", type(what_type_para))
print("type(CPerson.what_type_para) is ", type(CPerson.what_type_para))
print("type(person.what_type_para) is ", type(person.what_type_para))

what_type_para("haha")
CPerson.what_type_para()
person.what_type_para()


