#!/usr/bin/env perl
use warnings;
use strict;
use utf8;

my $strTest1 = "Cat: fish, fish, I want to eat fish\n Host: no, I have no fish\n";
my $strFind = "fish";

#1、index:从指定位置向后查找字符串
#2、rindex:从指定位置向前查找字符串
#3、length:返回字符串长度(与使用的字符集有关，use utf8;)
#4、pos:不知何意

#http://blog.chinaunix.net/uid-26000296-id-3491075.html

#1、index
#语法:
#	position=index(string,substring,position);
#解释:
#	返回子串substring在字符串string中的位置,如果不存在则返回-1。
#	参数position是可选项,表示匹配之前跳过的字符数,或者说从该位置开始匹配。
sub index_test()
{
	my $position = 0;
	my $iFindLen = length($strFind);
	while($position != -1)
	{
		$position = index($strTest1, $strFind, $position);
		if($position != -1)#if前置时后面必须要有花括号
		{
			print $position, " has \'fish\' string\n";
			$position += $iFindLen;#语句块的最后一个语句可以不用分号结尾
		}
	}
}

#2. rindex
#语法:
#	position=rindex(string,substring,position);
#解释:
#	与index类似，区别是从右端匹配。
#	这段测试代码比index_test要简介，虽然rindex写了两次。
sub rindex_test()
{
	my $position = rindex($strTest1, $strFind);
	my $iFindLen = length($strFind);
	while($position != -1)
	{
		print $position, " has \'fish\' string\n";
		$position -= 1;
		$position = rindex($strTest1, $strFind, $position);
	}
}

#3. length
#语法:
#	num=length(string);
#解释:
#	返回字符串长度，或者说含有字符的数目。
#	把use utf8;注释掉以后返回9
sub length_test()
{
	my $strTest1 = "天气好";
	print $strTest1, "'s length is ", length($strTest1), "\n";
}

#4. pos
#语法:
#	offset=pos(string);
#解释:
#	返回最后一次模式匹配的位置。


#5.substr
#语法:
#	substr(expr,skipchars,length)
#解释:
#	抽取字符串(或表达式生成的字符串)expr中的子串,
#	跳过skipchars个字符,或者说从位置skipchars开始抽取子串(第一个字符位置为0),
#	子串长度为length,此参数可忽略,意味着取剩下的全部字符。
#	当此函数出现在等式左边时,expr必须为变量或数组元素,此时其中部分子串被等式右边的值替换。

length_test();