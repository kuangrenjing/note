#!/usr/bin/env python
# coding=utf-8

'''
1、文档：
	https://docs.python.org/3/reference/executionmodel.html
	http://wiki.jikexueyuan.com/project/python-language-reference/execution-model.html
	http://python.jobbole.com/82604/
	https://www.cnblogs.com/JahanGu/p/7452527.html python2、3共存
'''

'''
2、程序的结构
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	python程序由代码块组成，代码块可以作为独立单元执行。譬如：一个模块；一个函数；一个
类定义；交互式模式下键入的每一条命令；一个脚本文件（作为解释器的标准输入或作为解释器的
命令行参数）；一个脚本命令（用法：解释器 -c 脚本命令）；传给内建函数eval和exec的参数。

	一个代码块在一个执行框架中执行。框架包括一些管理信息（用于debugging），框架还决定
在当前代码块执行完之后从哪里以及怎样继续执行过程。
'''

'''
3、命名和绑定：
3.1、绑定名字：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	名字引用对象。名字通过名字绑定操作引入。

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
The following constructs bind names: formal parameters to functions, 
import statements, class and function definitions (these bind the class 
or function name in the defining block), and targets that are identifiers 
if occurring in an assignment, for loop header, or after as in a with 
statement or except clause. The import statement of the form from ... import * 
binds all names defined in the imported module, except those beginning with 
an underscore. This form may only be used at the module level.

A target occurring in a del statement is also considered bound for this 
purpose (though the actual semantics are to unbind the name).

Each assignment or import statement occurs within a block defined by a 
class or function definition or at the module level (the top-level code block).


If a name is bound in a block, it is a local variable of that block, 
unless declared as nonlocal or global. If a name is bound at the module level, 
it is a global variable. (The variables of the module code block are local and global.) 
If a variable is used in a code block but not defined there, it is a free variable.

Each occurrence of a name in the program text refers to the binding of that name 
established by the following name resolution rules.

3.2、名字解析
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	作用域(scope)定义了代码块内的名字可见性。python的作用域比c语言的要繁琐，c语言只区
分全局作用域和块作用域，块作用域由{}定义和嵌套，非常简洁。python的作用域分为模块级，函
数级、类级等等，函数和类又可以嵌套定义，作用域是在编译时还是执行时决定，这都需要研究和了
解。

	代码块使用的名字在包围这个名字最近的作用域内解析，代码块的所有作用域合起来称为这个
代码块的环境。

	当一个名字根本没有被找到，NameError异常被抛出。当当前作用域是一个函数作用域，名字使
用时还没有被绑定，UnboundLocalError异常被抛出。UnboundLocalError是NameError的子类。

	python没有名字声明，但允许名字绑定发生代码块的任何位置


	当一个名字在一个代码块里发生了绑定，不管这个绑定操作发生在什么位置，这个代码块里使用
的都是这个绑


If a name binding operation occurs anywhere within a code block, all uses of the 
name within the block are treated as references to the current block. This can lead 
to errors when a name is used within a block before it is bound. This rule is subtle. 
Python lacks declarations and allows name binding operations to occur anywhere within 
a code block. The local variables of a code block can be determined by scanning the 
entire text of the block for name binding operations.

If the global statement occurs within a block, all uses of the name specified in the 
statement refer to the binding of that name in the top-level namespace. Names are 
resolved in the top-level namespace by searching the global namespace, i.e. the 
namespace of the module containing the code block, and the builtins namespace, 
the namespace of the module builtins. The global namespace is searched first. 
If the name is not found there, the builtins namespace is searched. The global 
statement must precede all uses of the name.

The global statement has the same scope as a name binding operation in the same block. 
If the nearest enclosing scope for a free variable contains a global statement, 
the free variable is treated as a global.

The nonlocal statement causes corresponding names to refer to previously bound 
variables in the nearest enclosing function scope. SyntaxError is raised at 
compile time if the given name does not exist in any enclosing function scope.

The namespace for a module is automatically created the first time a module 
is imported. The main module for a script is always called __main__.

Class definition blocks and arguments to exec() and eval() are special in the 
context of name resolution. A class definition is an executable statement that 
may use and define names. These references follow the normal rules for name 
resolution with an exception that unbound local variables are looked up in the 
global namespace. The namespace of the class definition becomes the attribute 
dictionary of the class. The scope of names defined in a class block is limited 
to the class block; it does not extend to the code blocks of methods – this 
includes comprehensions and generator expressions since they are implemented 
using a function scope. This means that the following will fail:
'''
a = 4

def scope_test_nameerror():
	c = a + b
	print("a+b is ", a)

def scope_test_unboundlocalerror():
	b = 6
	c = a + b
	a = 5
	print("a+b is ", a)

def scope_test_unboundlocalerror():
	b = 6

	c = a + b
	global a
	print("a+b is ", a)


scope_test_nameerror()
scope_test_unboundlocalerror()
#print("a is ", a)