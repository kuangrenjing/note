#!/usr/bin/env python
# coding=utf-8

'''
文档
	https://docs.python.org/3/reference/import.html
	http://python.usyiyi.cn/documents/python_352/reference/import.html
'''

'''
import过程：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	import语句由python interpreter解析，解析器的sys.meta_path处存放的是finder列表。
sys.meta_path是通过python库importlib填充的。解析器调用python库的方式可以方便我们定制
import系统的回调函数。

	解析器提供了两套import钩子挂载点：sys.meta_path(meta path hooks)、sys.path_hooks
(import path hooks)。

	sys.modules存储的是已经加载的模块，通过print(sys.modules.keys())可以查看哪些模块
已经被加载。

	sys、builtin等c语言实现的内建模块在python启动时就已加载，python解释器可以直接用它们，
但python程序还需要诸如import sys把sys引入本地命名空间才能使用。
'''

'''
import系统：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	模块中的代码通过import其它模块来获取那个模块的代码。import语句是一个最常用的import
机制的调用方法，但不是唯一的方法。其它的譬如importlib.import_module()函数、内建
__import__()函数也可以用来调用import机制

	import语句结合两个操作：它按名字寻找模块，然后把寻找的结果绑定到本地作用域的一个名
字上。import语句的搜寻功能是通过以合适参数调用__import__()函数完成的。然后用__import__()
函数的返回结果用来完成绑定操作。查看import语句的说明可以了解绑定操作的详细信息。

	直接调用__import__()函数完成模块的搜寻工作和模块对象的创建工作（如果找到），同时做一
些辅助工作：import父包，更新各种缓存（包括sys.modules），但只有import语句会完成名字绑定
操作。

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	当调用__import__()作为import语句的一部分时，将调用标准的内置__import__()。用于调
用导入系统的其他机制（例如importlib.import_module()）可以选择颠覆__import__()并使用其自己的解决方案来实现导入语义。

When calling __import__() as part of an import statement, the standard builtin 
__import__() is called. Other mechanisms for invoking the import system (such 
as importlib.import_module()) may choose to subvert __import__() and use its 
own solution to implement import semantics.

When a module is first imported, Python searches for the module and if found, it creates 
a module object [1], initializing it. If the named module cannot be found, a ModuleNotFoundError 
is raised. Python implements various strategies to search for the named module when 
the import machinery is invoked. These strategies can be modified and extended by using 
various hooks described in the sections below.

Changed in version 3.3: The import system has been updated to fully implement the second 
phase of PEP 302. There is no longer any implicit import machinery - the full import 
system is exposed through sys.meta_path. In addition, native namespace package support 
has been implemented (see PEP 420).
'''

'''
1、importlib
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	importlib提供了丰富的API用来和import系统交互(什么是import系统)。譬如
importlib.import_module()函数是一个比内建__import__()函数简单的importAPI
The importlib module provides a rich API for interacting with the 
import system. For example importlib.import_module() provides a recommended, 
simpler API than built-in __import__() for invoking the import machinery. 
Refer to the importlib library documentation for additional detail.

'''

'''
3、搜寻
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	要开始搜索，Python需要被导入模块（或包，但为了讨论的目的，区别是无关紧要的）的完全
限定(fully qualified)名称。此名称可能来自import语句的各种参数，或者来自
importlib.import_module()函数或__import__()函数的参数。

	此完全限定名称将用于导入搜索的各个阶段，譬如名字中还有'.'，意味着有子模块需要加载。
譬如：foo.bar.baz，在这种情况下，Python首先尝试导入foo，然后foo.bar，最后导入
foo.bar.baz。如果任何中间子模块导入失败，将会抛出一个ModuleNotFoundError异常。

3.1、模块缓存
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	模块加载成功以后其名字与模块对象的对应关系存储在sys.modules对象中，一个模块对象在
sys.modules中可以存在多个条目(譬如使用import as语句)。sys.modules是可写的，可以把key
的value置None(此后再加载此name的模块会引发ImportError错误)或删除key。




	搜寻期间查找的第一个位置是sys.modules。这个对象存储了先前已经导入的模块或包对象。


在导入搜索期间检查的第一个位置是sys.modules。此映射用作先前导入的所有模块的缓存，包括中间路径。
So if foo.bar.baz was previously imported, sys.modules will contain entries for foo, 
foo.bar, and foo.bar.baz. 每个键将具有作为其值的相应模块对象。

在导入期间，在sys.modules中查找模块名称，如果存在，则关联的值是满足导入的模块，并且该过程完成。
但是，如果值为None，则会引发ImportError。如果模块名称丢失，Python将继续搜索模块。

sys.modules是可写的。删除键可能不会破坏关联的模块（因为其他模块可能保存对它的引用），
但它将使指定模块的缓存条目无效，导致Python在下次导入时重新搜索指定的模块。该键也可以分配给None，
强制下次导入模块导致ImportError。

注意，如果你保留对模块对象的引用，在sys.modules中使其高速缓存条目无效，然后重新导入命名的模块，这两个模块对象将不相同。相比之下，importlib.reload()将重用相同的模块对象，只需通过重新运行模块的代码重新初始化模块内容。

The first place checked during import search is sys.modules. This mapping serves as a cache of all modules that have been previously imported, including the intermediate paths. So if foo.bar.baz was previously imported, sys.modules will contain entries for foo, foo.bar, and foo.bar.baz. Each key will have as its value the corresponding module object.

During import, the module name is looked up in sys.modules and if present, the associated value is the module satisfying the import, and the process completes. However, if the value is None, then a ModuleNotFoundError is raised. If the module name is missing, Python will continue searching for the module.

sys.modules is writable. Deleting a key may not destroy the associated module (as other modules may hold references to it), but it will invalidate the cache entry for the named module, causing Python to search anew for the named module upon its next import. The key can also be assigned to None, forcing the next import of the module to result in a ModuleNotFoundError.

Beware though, as if you keep a reference to the module object, invalidate its cache entry in sys.modules, and then re-import the named module, the two module objects will not be the same. By contrast, importlib.reload() will reuse the same module object, and simply reinitialise the module contents by rerunning the module’s code.



              +-----------+   +-----------+  +-----------+
sys.meta_path |built-in   |   |frozen     |  |import path|
              +-----------+   +-----------+  +-----------+ 