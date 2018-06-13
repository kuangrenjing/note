#!/usr/bin/env python
# coding=utf-8

'''
http://python.usyiyi.cn/documents/python_352/reference/lexical_analysis.html
https://docs.python.org/3/reference/lexical_analysis.html
'''

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、物理行与逻辑行：
	物理行：像普通文本文件一样用LF(\n Unix)或CR LF(\r\n Windows)作为分割从源代码中取
出的一串串字符串就是物理行。

	逻辑行：一般一个逻辑行就是一个物理行，但python可以通过显式的或隐式的行连接把多个物
理行表示为一个逻辑行。词法分析器解析出一个逻辑行后会在符号流中加入一个NEWLINE词符供后面
解析器(parser)识别逻辑行。

	显式的行连接：在物理行的最后加一个反斜杠。

	隐式的行连接：圆括号，方括号或花括号中的表达式可以在不使用反斜杠的情况下把多个物理行
归为一个逻辑行。
'''

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
2、缩进(Indentation)、缩进级别：
	我们知道、编程语言里的复合语句有子语句，而复合语句又可以嵌套，即这些语句之间是有层级
的，一边的编程语言通过花括号（c, javascript等）或者标记（perl、lua等）划分层级。而python
是通过缩进级别来划分子语句的对应的。

	逻辑行开头处的前导空白字符(空格和制表符)用于计算行的缩进级别，而后者又用于确定语句的
分组。缩进级别用空格数目来衡量，不同空格数目代表不同的缩进级别，制表符会转化为空格，一个制
表符会转化为多少空格呢？规则是替换的空格数加上原有空格数是8的倍数(但尽量小)，所以替换成
1-8个空格都有可能。

	逻辑行第一个字符如果是换页符，它将会被缩进级别计算过程忽略，但如果换页符出现在空白字符
的中间，那行为是未定义的。

	显式的行连接符反斜杠用在前导空白之间是不可以的。
	eg:
	\
    $variable = 10 #这会导致报错(IndentationError: unexpected indent)

	第一级语句前有空格也是不可以的
	eg:
 variable1 = 10 #错误
'''

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
3、tokens(记号)
	标识符(identifiers)(变量名，函数名？)、关键字(keywords)、字面量(literals)、操作符(operators)、分割符或定界符(delimiters)
	NEWLINE INDENT DEDENT
Besides NEWLINE, INDENT and DEDENT, the following categories of tokens exist: 
identifiers, keywords, literals, operators, and delimiters. Whitespace 
characters (other than line terminators, discussed earlier) are not tokens, 
but serve to delimit tokens. Where ambiguity exists, a token comprises the 
longest possible string that forms a legal token, when read from left to right.

标识符：
	2.x版本仅支持ASCII，大小写的A-Z，_，数字(但不能作为第一个字符)
	3.x版本支持UNICODE字符

运算符：
+       -       *       **      /       //      %      @
<<      >>      &       |       ^       ~
<       >       <=      >=      ==      !=
解释：
+  算术加
-  算术减
*  算术乘
** 算术幂
/  算术除
// 算术整除
%  算术取余
@  v3.5新增的运算符


定界符：
(       )       [       ]       {       }
,       :       .       ;       @       =       ->
+=      -=      *=      /=      //=     %=      @=
&=      |=      ^=      >>=     <<=     **=
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	句号也可以出现在浮点数或虚数字面量中。连续的三个句号在复数字面量里有特殊含义。表中后
面两行是增强型赋值运算符（类似C语言中的复合赋值运算符），既是运算符又是定界符。
The period can also occur in floating-point and imaginary literals. A sequence 
of three periods has a special meaning as an ellipsis literal. The second half 
of the list, the augmented assignment operators, serve lexically as delimiters, 
but also perform an operation.
'''

'''
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
3、token的分割：
默认分割
2.1.9. Whitespace between tokens
Except at the beginning of a logical line or in string literals, the whitespace 
characters space, tab and formfeed can be used interchangeably to separate tokens. 
Whitespace is needed between two tokens only if their concatenation could otherwise 
be interpreted as a different token (e.g., ab is one token, but a b is two tokens).
'''

