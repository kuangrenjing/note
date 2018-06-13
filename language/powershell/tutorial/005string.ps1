<#
双引号字符串会进行内插处理，转义处理（转义字符是``）
单引号字符串不会做内插处理，支持单引号转义（转义字符是单引号）
#>

<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
双引号内的变量替换：
http://www.pstips.net/expanding-variables-in-strings.html

字符串内的变量展开只会到值，不会做数组下标或属性展开，为了应对这种状况，可以使用双
层美元符号的方法进行弥补，如：
    "$($args[0])"
    "$($host.UI.RawUI.BackgroundColor)"
#>