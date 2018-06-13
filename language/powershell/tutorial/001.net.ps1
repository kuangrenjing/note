<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、一句话说明.net是什么:
    .NET是一种面向网络、支持各种用户终端的开发平台环境。

    一种编程环境要面向web，肯定就要提供大量web相关的类库，这是毋容置疑的。如果用.net史
前方法要给每一种语言的每一个编译器提供一套类库，相当繁琐。.net的目标是向上兼容各种编程
语言，向下兼容各种操作系统/硬件平台。试想你想开发一套网络通信系统，VC++, VB程序员可以分
工协作，发布一个统一的安装包，windows、linux、安卓上都能安装运行，这开发成本，老板睡觉都
能乐醒。
#>

<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
2、公用语言运行时(CLR):
    .NET提供了一个运行时环境叫做公用语言运行时，它管理着代码的执行并使得开发过程变得更
加简单。这是一种可操控的执行环境，其功能通过编译器与其它工具共同展现。你的代码将受益于这
一环境：跨语言集成、跨语言异常处理、增强的安全性、版本处理与开发、支持简单的组件交互模型以
及调试服务（当然你得使用面向运行时环境的编译器）

    为了使运行时环境能够向可操控代码提供服务，语言编译器需要产生一种元数据，它将提供在
你使用语言中的类型成员引用的信息。元数据与代码一起存储，每个可加载的CLR映像均包含了元数
据。运行时环境使用元数据定位并载入类，在内存中展开对象实例，解决方法调用，产生本地代码(
JIT)，强制执行安全性，并建立运行时环境的边界。

    可以认为元数据是虚拟对象系统(VOS)的描述语言。
#>

<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
3、.net程序静态组成与动态组成
    静态：由面向.net的编译器编译成MSIL，元数据同时生成；
    动态：CLR负责管理运行。
#>

<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
4、.net与C#
    可以认为C#是直接面对.net设计的编程语言。它没有自己的运行库，许多强大的功能均来自.NET
平台的支持。C#也没有自己的基础数据类型，都是使用的.NET的数据类型。.net的所有类型都是对象，
所以C#, powershell也一样。
#>