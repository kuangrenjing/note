#!/usr/bin/env python
# coding=utf-8

'''
1、文档：
	https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431864715651c99511036d884cf1b399e65ae0d27f7e000
'''

'''
2、类和实例
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	面向对象最重要的概念就是类（Class）和实例（Instance），必须牢记类是抽象的模板，比
如Student类，而实例是根据类创建出来的一个个具体的“对象”，每个对象都拥有相同的方法，但
各自的数据可能不同。

	在Python中，定义类是通过class关键字，class后面紧接着是类名，即Student，类名通常是
大写开头的单词，紧接着是(object)，表示该类是从哪个类继承下来的，继承的概念我们后面再讲，
通常，如果没有合适的继承类，就使用object类，这是所有类最终都会继承的类。

	定义好了Student类，就可以根据Student类创建出Student的实例，创建实例是通过类名+()
实现的：
'''
class Student(object):
	pass

bart = Student()

'''
可以自由地给一个实例变量绑定属性，比如，给实例bart绑定一个name属性和一个score属性：
'''
bart.name = "xiaoming"
bart.score = 59
print("bart.score is ", bart.score)

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	由于类可以起到模板的作用，因此，可以在创建实例的时候，把一些我们认为必须绑定的属性
强制填写进去。通过定义一个特殊的__init__方法，在创建实例的时候，就把name，score等属性
绑上去(__init__方法就像是c++语言里的构造函数)：
'''
class Student2(object):
	def __init__(self, name, score):
		self.name = name
		self.score = score

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	注意到__init__方法的第一个参数永远是self，表示创建的实例本身，因此，在__init__方
法内部，就可以把各种属性绑定到self，因为self就指向创建的实例本身。

	有了__init__方法，在创建实例的时候，就不能传入空的参数了，必须传入与__init__方法
匹配的参数，但self不需要传，Python解释器自己会把实例变量传进去：
'''
cfq = Student2("chenfeiqian", 100)
mqs = Student2("maquansheng", 98)
print("cfq.score is ", cfq.score)
print("mqs.score is ", mqs.score)

'''
3、类函数与普通函数比较：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	和普通的函数相比，在类中定义的函数只有一点不同，就是第一个参数永远是实例变量self，
并且，调用时，不用传递该参数。除此之外，类的方法和普通函数没有什么区别，所以，你仍然可以
用默认参数、可变参数、关键字参数和命名关键字参数。
'''

'''
4、数据封装：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	类的成员函数至少需要一个参数，这个参数就是self，类的数据成员就是通过这个self访问的。
定义没有参数的类成员函数会报错。
'''
class Student3(object):
	def __init__(self, name, score):
		self.name = name
		self.score = score

	def test(self):
		print("Hello world")

student_test = Student3("limei", 75)
student_test.test()