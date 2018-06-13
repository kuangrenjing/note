#!/usr/bin/env python
# coding=utf-8

'''
教程
	https://docs.python.org/3/tutorial/modules.html
	http://python.usyiyi.cn/documents/python_352/tutorial/modules.html
'''

'''
简介：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	当我们退出python解释器后再进入，之前定义的函数和变量都丢失了。所以当我们要写一个长
的程序时，就不应该在交互模式下进行，而是应该用编辑器写一个程序文件，然后把这个文件作为
解释器的输入，这就是脚本编程，而那个文件就是脚本文件。当我们的程序变得越来越大时，维护
将变得非常麻烦。我们可能会遇到多个程序都需要同一个功能函数的情况，在多个程序中维护这个
函数的定义是不明智的。

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	所以python引入了模块来解决代码维护和代码复用的问题。模块是一个文件，其文件名是：
'模块名'.py，在模块内，模块名可以通过__name__获取。把需要被多次使用的变量和函数定
义放在一个文件中，通过“import”语句可以把这个文件中定义引入其它模块。
'''

'''
1、模块进阶
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	模块除了可以包含类、函数等定义，还可以包含可执行语句。这些语句用于初始化模块，它们在
模块被加载时运行(首次执行相应模块的import语句)。

	每个模块都有它们自己的符号表，这个符号表是模块的全局符号表，所以我们不用担心模块符
号会和引入者的符号冲突。引入者可以通过模块命名空间获取模块的符号表。

	模块可以import其它模块。一般情况下（但非强制），我们把import语句放在模块文件或脚本
文件的开头。被import进来的模块的命名空间被放置在模块或脚本的全局符号表下。

	import语句的若干种用法：譬如我们有一个fibo.py文件，fibo.py定义了fib(n)、fib2(n)
两个函数。
	import fibo #fibo命名空间被放在当前全局符号表内，fibo.fib指向fib(n)函数
	import fibo as fibo_hei #fibo_hei命名空间被放在当前全局符号表内
	from fibo import fib   #当前全局符号表内fib名字直接指向fib(n)函数
	from fibo import fib as fibo_fib  #当前符号表内fibo_fib名字指向fib(n)函数
	from fibo import * #fibo.py符号表内的符号都直接放到了当前全局符号表内，但不包括
						下划线开头的符号。

	一次python解释器会话期间，模块只会被加载一次，所以如果我们更新了模块，我们必须重启
解释器。python提供了reload(modulename)函数，但好像其使用具有局限性。
'''

'''
1.1、把模块作为脚本执行：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	运行python fibo.py <arguments>，fibo.py脚本内的可执行语句将会执行，但模块的
__name__名字会被置为"__main__"。利用文件作为模块和脚本时__name__会不同的特性，我们可以
做很多工作。譬如做模块的测试工作，模块作为脚本运行时发出警告信息等等。
'''

'''
1.2、模块搜寻路径：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	当一个模块名spam被import时，解释器先搜寻内建模块。如果没有找到，在sys.path路径列表
中寻找sys.path文件。sys.path是按这样的顺序初始化的：
	当前调用import语句的模块或脚本所在目录（当前目录）
	PYTHONPATH（跟shell变量PATH的语法相同）
	python的安装目录

	python程序可以修改sys.path的配置。
'''

'''
1.3、编译python文件：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	脚本语言一般是即时编译，python也是如此。但python会尝试把编译结果保存下来，这样下次
启动时就快了。模块编译结果保存和过期判断都是自动的，不需要外部干预。编译结果保存失败或被
删除也不要紧，无非就是启动慢了一些。

	对python3而言，spam.py模块的编译结果是__pycache__/spam.cpython-33.pyc(33是版本
号)。这个命名方式运行多个版本的python的编译结果共存。同时，编译结果还是平台无关的，在不
同平台间分享编译结果是可行的。基于此，python程序可以不带源代码发布（这需要一些特殊设置）。
此外，python不会给从命令行引入的模块保存编译结果，所以脚本是需要源码发布的。

python编译的一些高级技术：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	You can use the -O or -OO switches on the Python command to reduce the size 
of a compiled module. The -O switch removes assert statements, the -OO switch 
removes both assert statements and __doc__ strings. Since some programs may rely 
on having these available, you should only use this option if you know what 
you’re doing. “Optimized” modules have an opt- tag and are usually smaller. Future 
releases may change the effects of optimization.

	A program doesn’t run any faster when it is read from a .pyc file than when 
it is read from a .py file; the only thing that’s faster about .pyc files is the 
speed with which they are loaded.

	The module compileall can create .pyc files for all modules in a directory.

	There is more detail on this process, including a flow chart of the decisions, 
in PEP 3147.
'''

'''
2、标准模块：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	Python发行时会携带一个标准模块库，“Python Library Reference”详细描述了这个库。其
中一些模块是解释器用C语言实现的
	Python comes with a library of standard modules, described in a separate 
document, the Python Library Reference (“Library Reference” hereafter). Some modules 
are built into the interpreter; these provide access to operations that are not part 
of the core of the language but are nevertheless built in, either for efficiency or to 
provide access to operating system primitives such as system calls. The set of such 
modules is a configuration option which also depends on the underlying platform. 
For example, the winreg module is only provided on Windows systems. One particular 
module deserves some attention: sys, which is built into every Python interpreter. 
The variables sys.ps1 and sys.ps2 define the strings used as primary and secondary prompts:
'''



