#!/usr/bin/python
# -*- coding: UTF-8 -*-

#类与对象的使用

class CPerson():
	a = 8
	kind = "black"
	def __init__(self, name):
		self.name =name

	def print_name(self):
		print(self.name)

	@classmethod
	def print_kind(cls):
		print(CPerson.kind)

person = CPerson('mqs')


#print("CPerson's type is ", type(CPerson))
#print("person's type is ", type(person))
#print("person's a is ", person.a)

print(type(person.print_name))
print(type(person.print_kind))
print(type(CPerson.print_kind))

CPerson.print_kind()