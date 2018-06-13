<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、函数的结构由三部分组成：函数名，参数，函数体
Function FuncName （args[]）
{
    code;
}
#>

<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
2、无参函数：
无参函数的定义：
    function funcname
    {
        code
    }
无参函数的调用：
    funcname
#>
function say_hello
{
    write-host "hello, every one"
}

say_hello

<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
3、有参函数：
函数参数的操作：Powershell函数可以接受参数，并对参数进行处理。函数的参数有3个特性：
    隐形参数：内部变量$args 接受函数调用时接受的参数，$args是一个数组类型。
    命名参数：函数的每一个参数可以分配一个名称，在调用时通过名称指定对应的参数。(也可以
使用param关键字？)
    预定义参数：函数在定义参数时可以指定默认值，如果调用时没有专门指定参数的值，就会保
持默认值。

命名参数函数定义：
    需使用圆括号把参数列表括起来，参数之间使用逗号分割，形如：
        function add($arg1, $arg2)
        {
            write-host "arg1 is $arg1"
            write-host "arg2 is $arg2"
            write-host "args[0] is $($args[0])"
        }

隐形参数函数定义：
    没有参数列表，函数体中使用args数组。
        function add
        {
            write-host "args[0] is $($args[0])"
            write-host "args[1] is $($args[1])"
        }

带参函数调用的总体特征：参数列表不要用圆括号，参数之间用空白隔开，不要用逗号
    函数名 参数 参数 参数 参数...

命名参数函数的调用方式：
    需显式地指定命名参数，方式是：[-参数名  参数值]，如：
        add -arg1 1 -arg2 2

隐式参数函数的调用方式，如：
    add 1 2

命名参数与任意参数共存，如：
    add -arg2 1 -arg1 2 3 4
    则args[0]为3，args[1]为4
#>

function para_func($arg1, $arg2)
{
    write-host "arg1 is $arg1"
    write-host "arg2 is $arg2"
    write-host "args[0] is $($args[0])"
    write-host "args[1] is $($args[1])"
}

para_func -arg2 3 -arg1 1
para_func -arg1 1 -arg2 3 5 8
