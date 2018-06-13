#!/usr/bin/env python
# coding=utf-8

'''
文档：
	https://docs.python.org/3/reference/datamodel.html
'''

'''
Data model:

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、objects, values 和 types：
	对象是python的数据抽象。python中的所有数据都可以使用对象或对象之间的关系表示（包括
程序）。

	所有对象都有一个标识，类型和值。

	对象的标识一旦建立就永远不会改变，我们可以认为它就是对象在内存中的地址。is操作符比较
两个对象的标识；id函数返回标识的整数表示。

	CPython实现： id(x)函数返回的就是x对象的内存地址

	对象类型决定了对象支持的操作和对象的取值。type()函数返回对象的类型（本身也是一个对象
），对象的类型也是不可改变的（在某些特殊情况下，类型可以改变）。

	某些对象的值是可以改变的。值可变的对象称为mutable对象，值不可改变的对象称为immutable
对象(The value of an immutable container object that contains a reference to a 
mutable object can change when the latter’s value is changed; however the container 
is still considered immutable, because the collection of objects it contains cannot 
be changed. So, immutability is not strictly the same as having an unchangeable 
value, it is more subtle.) 

	对象值的可更改性由它的类型决定。譬如，numbers、strings、tuples是immutable对象，而
dictionanries、lists是mutable对象。

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	当需要一个immutable对象时,实现可能会使用一个已经存在的具有相同值的immutable对象代
替，当然这不是强制的，不同的实现可能不同。mutable对象则不能这样做。

	对象永远不显式销毁。当对象不可达时，它可能会被garbage-collected。An implementation 
is allowed to postpone garbage collection or omit it altogether — it is a matter 
of implementation quality how garbage collection is implemented, as long as no 
objects are collected that are still reachable.

	CPython实现：CPython垃圾回收目前主要使用引用计数方案，引用计数变为0时对象就被实时
回收，但这个方案不能保证循环引用垃圾的回收，需其它可选方案配合使用，且具有延迟性。垃圾
回收方案和策略语言并没有强制规定，与实现相关，所以任何时候我们的程序都不应依赖“对象不
可达时就立即消亡”这条错误规则。

	注意：使用tracing或debugging工具、异常捕获语句‘try...except’可能会阻止gc对相关对
象的回收。

	一些对象包含对外部资源的引用，譬如文件或者窗口。对象被回收时这个资源也随之释放，但
Python实现并不能保证垃圾回收总是会发生。所以，这些对象提供了一个显式方法去释放外部资源，
通常是close()方法。官方推荐在‘try...finally’语句和‘with’语句中做这项工作。

	一些对象包含对其它对象的引用，这些对象称为容器(container)，譬如元组、列表、字典等等。
容器的值就是所有引用对象的值(可能是一个很深的递归)。总之：我们说容器的值，指的是容器所容
对象的值，说容器的mutability，指的是容器直接引用对象的标识。例子：一个immutable容器包含
一个mutable对象，这个mutable对象的值改变了，那容器的值也就改变了，但容器是immutable的。

	总结：如果把python对象想象成一颗树，mutability只管节点的子，而值要一直延伸到叶子。

2、标准类型层次结构
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

Below is a list of the types that are built into Python. Extension modules 
(written in C, Java, or other languages, depending on the implementation) 
can define additional types. Future versions of Python may add types to the 
ype hierarchy (e.g., rational numbers, efficiently stored arrays of integers, 
etc.), although such additions will often be provided via the standard library instead.

Some of the type descriptions below contain a paragraph listing ‘special attributes.’ 
These are attributes that provide access to the implementation and are not intended 
for general use. Their definition may change in the future.
'''




print("type(None) is ", type(None))