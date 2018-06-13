
<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
If（条件满足）{
如果条件满足就执行代码
}
Else
{
如果条件不满足
}
#>

$variable1 = 10
if($variable1 -gt 10)
{
    write-host "> 10"
}
else
{
    write-host "not > 10"
}


<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    如果你知道循环的确切次数可以使用For循环，For循环属于计数型循环，一旦达到最大次数，
循环就会自动终止。下面的例子通过循环求1-100的数列和。
#>

$sum=0
for($i=1;$i -le 2;$i++)
{
    $sum+=$i
}
$sum