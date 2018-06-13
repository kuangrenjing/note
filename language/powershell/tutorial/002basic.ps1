<#
1、教程：
    在线中文教程：http://www.pstips.net/powershell-online-tutorials
#>

<#
1、注释：

    虽然PowerShell脚本大量遵从C#的语法规则，但C#的注释符不能在PowerShell中使用。
powershell使用的是类似cmd的注释方法。但又分为单行注释和多行注释：

    单行注释范例：
        #这是一个单行注释

    多行注释范例：
        <#多行注释对的第1行
        多行注释对的第2行
        多行注释对的第3行
        多行注释对的第4行
        多行注释对的第5行
        #\>
#>

<#
2、cmdlet、cmdlets

	一个cmdlet是一个在powershell环境中使用的轻量级的命令，它是.net框架类型的一个实例，
而不是可执行程序（这是区别于其它shell命令的显著特点）。cmdlets是所有cmdlet的实例。
PowerShell绝对是学习.Net Framework的好工具，这句话是PowerShell团队中某人说的，实际
确实如此，我们可以通过Get-Member来窥探.Net中很多神秘的元素。

    cmdlet的类型名为System.Management.Automation.CmdletInfo，可以通过get-member查看
属性和方法。

常用cmdlet：

[1]、获取类
    Get-Command: 得到所有PowerShell命令，获取有关 cmdlet 以及有关 Windows PowerShell
命令的其他元素的基本信息。包括Cmdlet、Alias、Function。

[2]、正则类
    select-string: 跟linux中的grep类似。通过get-command、猜名字、select-string就可以找
到很多有用的cmdlet了。

[3]、网络类
#>

<#
psobject、ATS、ETS
    https://blogs.msdn.microsoft.com/besidethepoint/2011/11/22/psobject-and-the-adapted-and-extended-type-systems-ats-and-ets/
    https://msdn.microsoft.com/en-us/library/ms714674(v=vs.85).aspx

    psobject是对象的一个成员，本身也是一个类类型。msdn对它的解释是：在windows powershell环境
中可以以一种统一的视角去看待任何对象。psobject具体又是通过Adapted Type System (ATS)和Extended 
Type System (ETS)来实现这种统一性的。
In conclusion, it should now be clear that PowerShell is not at all only a .NET shell. 
Instead, it has been designed with deep consideration for out-of-the-box and customizable 
interaction with all kinds of objects and object frameworks.
#>
$proc = Get-Process explorer
$proc.psobject 


<#
3、get-help

机器上可能没有帮助文件，那get-help仅显式部分帮助，可以根据提示进行安装或转到在线帮助。



3、powershell输入输出：
Write-Host hello world

4、给脚本传入变量：
write-host "args: $($args[1]), $($args[2])"

5、转义字符
powershell的双引号内转义字符是`而不是\，单引号内转义符号是'，它只能转义单引号
#>
