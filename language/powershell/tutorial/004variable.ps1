<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、数据类型：
    变量与数据类型是分不开的。c#的数据类型可以分为两大部分：值类型和引用类型：

值类型：
    这种类型的变量直接保存变量值，包括：简单类型、结构体类型、枚举类型；

引用类型：
    这种类型的变量不直接存储所包含的值，而是指向它所要存储的值，包括类、代表、数组、接口

值类型与引用类型的equals()函数：
#>

<#
#>
write-host "system.int32's member is: "
[system.int32]|get-member|out-default

<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
虽然引用类型和值类型都是对象,但内存分配的位置不一样,一个在堆一个在栈
要从栈到堆就要装箱运过去
#>
[system.object]$v11 = 10
(,$v11)|get-member|out-default

<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
自定义类型(custom types)
    Windows PowerShell 5.0版本开始支持直接创建.NET Classes，这点可以说是非常强大的。
从微软官方公开的信息可以得知，在PowerShell中可以使用正统标准的类似真正面向对象的语法，
其目标也是为了开发者和IT专业人士能够将PowerShell应用到更广的应用和开发场景。

    https://stackoverflow.com/questions/59819/how-do-i-create-a-custom-type-in-powershell-for-my-scripts-to-use
#>
function self_define_type_test($firstname, $lastname, $phonenum)
{
    $person = new-object PSObject

    $person | add-member -type NoteProperty -Name first_name -Value $firstname
    $person | add-member -type NoteProperty -Name last_name -Value $lastname
    $person | add-member -type NoteProperty -Name phone_num -Value $phonenum

    return $person
}

$person = self_define_type_test "ma" "victor" "13861981369"

write-host "person is $person"

$person.gettype|out-default

<#
2、system.int32
http://www.cnblogs.com/hyddd/archive/2009/06/19/1506400.html
https://msdn.microsoft.com/en-us/library/system.int32(v=vs.110).aspx
#>

$type_test_v1 = 10
$type_test_v2 = $type_test_v1

if($type_test_v2.equals($type_test_v1))
{
    write-host '$type_test_v1 == $type_test_v2'
}


<#
变量可以临时保存数据，因此可以把数据保存在变量中，以便进一步操作。

1、赋值操作符：
    赋值操作符为“=”，几乎可以把任何数据赋值给一个变量，甚至一条cmdlet命令，
为什么，因为Powershell支持对象，对象可以包罗万象。

2、特殊的变量：子表达式
    由 $+圆括号+表达式 构成的变量属于子表达式变量，这样的变量会先计算表达式，
然后把表达式的值返回。例如 变量$(3+6)，可以简写成（3+6）,甚至可以简写成3+6。
譬如(3+6).gettype()

3、获取变量的属性和方法
Get-Member -inputobject $variable
使用管道是不靠谱的$variable|Get-Member

2、变量类型：

2、定义
    2.1、数值、字符串变量定义：
        $number1 = 10
        $number2 = 4
        $number3 = $number1*$number2
        $string1="保存文本"
        ${string2 $}="mossfly"
    2.2、数组变量定义：
        $array1 = 1,6,"friend","age:8"
        $array2 = 1..10
        $array3 = @()                   #空数组
        $array4 = ,"today"              #一个元素的数组
        $array1[0]                      #访问数组元素
    2.3、哈希变量定义：
        $hash1 = @{Name = "小明"; Age= 12; sex = "男"}

3、输出
    3.1、数值、字符串变量输出：
        $string1
    3.2、数组变量输出：
        $array4
    3.3、哈希变量输出：
        $hash1
#>

#变量定义、输出测试
$number1 = 10
$number2 = 4
$number3 = $number1*$number2
$string1="save file"

$array1 = 1,6,"friend","age:8"
$array2 = 1..10
$array3 = @()        #空数组
$array4 = ,"today"   #一个元素的数组

$hash1 = @{Name = "victor"; Age= 12; sex = "man"}


write-host '$number3 is ' $number3
write-host '$string1 is ' $string1


write-host '$array1 is ' $array1
write-host '$array1[2] is ' $array1[2]
write-host '$array4 is ' $array4
write-host '$array1.count is ' $array1.count

write-host '$hash1 is ' $hash1

write-host '$number3''s type is ' $number3.gettype().name

$type1 = $number1.gettype()
$type2 = $type1.gettype()

write-host 'type1''s type is ' $type2

write-host "array3's type is " $array3.gettype()
#$array1|Get-Member

#$array1|get-member
#$array1.count
#$array1.length

#get-member -inputobject $array1
#$variable1 = ($array1)[0]
if($array1.isfixedsize)
{
    write-host '$array1 is fixedsize'
}
(,$array1)|get-member|out-default


$variable1 = New-Object -TypeName System.object
$variable1 =10
$variable1|get-member|out-default

#$array1.add("cfq")
#write "$array1 is " $array1

$number4 = 10
$number5 = $number4
if($number4.equals($number5))
{
    write-host '$number4 == $number5'
}


<#
http://www.pstips.net/speeding-up-arrays.html
#>
#Measure-Command {
$ar = New-Object -TypeName System.Collections.ArrayList

for ($x=0; $x -lt 2; $x++)
{
    $ar.Add($x)|out-null
}

(,$ar)|get-member|out-default
#}

#Measure-Command