#!/usr/bin/env perl
use warnings;
use strict;
use utf8;

#变量类型（variable type）
#各类型魔符(sigil)：
#	标量(scale): $
#	数组(array): @
#	哈希(hash) : %
#
#魔符的作用：
#	perl通过变量标识符前的魔符来区分它是什么类型的
#变量。所以不管你取什么名字，都不会和perl自带的函数或操作符的写
#法相冲突。
#	不同的魔符拥有不同的命名空间，我们知道不同的命名空间内
#可以取相同的名字，所以$fred，@fred不会冲突。
#	魔符除了可以区分命名空间，还可以表明变量的使用意图，譬
#如$name[0]，这里魔符修饰的应该是name[0]，它是一个标量，虽然
#存在于数组空间的，我们还是使用了标量魔符。
#
#标量、数组、哈希定义：
#	标量：表示单个事物，又细分为数值、字符串、undef。它们之间通
#常可以内部相互转换。
#	数组：标量的有序集合，但不限于同类标量。
#	哈希：一些键-值对组成的结构，键只能是字符串且唯一。不是字
#符串自动转化为字符串，不唯一时后面加入的覆盖前面的。
#
#标量、数组、哈希的大小限制：
#	没有限制，都是以可用内存上限为界，可劲造吧。
#
#标量、数组、哈希字面量：
#	标量字面量：
#		单引号字符串除了单引号和在单引号、反斜杠前的反斜杠，其
#它字符都代表它们本身，要表示单引号和反斜杠需使用反斜杠转
#义,反斜杠只有在单引号或反斜杠之前才表示反斜杠，其它时候也
#只是表示它本身；
#		双引号字符串内才能使用各种转义字符，譬如换行符；
#
#	数组字面量：
#		范围操作符..:从左边数字计数到右边数字，每次加1，以产生
#一连串的数字（注意只能正向加1）。
#
#标量、数组、哈希赋值：
#
#标量、数组、哈希元素个数：这个涉及到标量上下文和数组上下文，
#但注意不存在哈希上下文。
#	字符串字符个数：length($string)函数
#	数组元素个数：把数组引用放在标量上下文中，譬如$num=@array。
#	哈希元素个数：把哈希转化为数组然后用在标量上下文中，譬如
#$num = keys %hash。（$num = %hash返回的是当前使用的槽位数-1/
#总槽位数）。
#
#标量、数组、哈希常用函数：
#	标量：
#		chomp函数：
#
#	undef:
#		undef值：如果我们没有显式地对一个标量变量初始化，那它的默认
#初始值为undef。undef在perl里是空无一物的意思，把它当数值它是0，
#当字符串它是空字符串，但其实它既不是数值也不是字符串，而是完全
#不同的一种标量类型。
#
#		undef值的比较：直接使用比较运算符比较值为undef的变量或undef
#字面量都会触发警告，拿undef字面量赋值不会触发警告。正确的undef
#判断应使用defined函数。
#
#		defined函数：标量值为undef，返回假；标量值不为undef，返回真。
#defined(0)、defoned("")都返回真。
#
#	列表、数组：本质上，列表指的是数据，数组指的是变量，但实际上经常混
#用。
#
#	一种特殊的列表字面量：($fred, $barney, $dino)，使用标量变量生成
#了一个列表字面量，关键是这个字面量可以出现在赋值符的左边，太神奇了。
#因为这个特性，我们可以很容易地做标量值的互换，我们知道在c语言中这需要
#三条语句，而在perl中($fred, $barney) = ($barney, $fred)一条语句就
#可以完成。


sub undef_test()
{
	#my $undef_test;
	my $undef_test2 = undef;

	if(!defined($undef_test2))
	{
		print 'defined($undef_test2) true', "\n";
	}

	if($undef_test2 == undef)
	{
		print '$undef_test2 == undef true', "\n";
	}

	if($undef_test2 == 0)
	{
		print '$undef_test2 == 0 true', "\n";
	}
}


sub scale_array_test()
{
	my $scale1 = "scale1";
	my $scale2 = "scale2";
	my $scale3 = "scale3";

	my @array = ($scale1, $scale2, $scale3);

	$array[1] = "array_scale2";

	print $array[0], "  ", $array[1], "  ", $array[2], "\n";
	print $scale2, "\n";
}


sub element_number_test()
{
	my %hash1 = ('a'=>11, 'b'=>2, 'c'=>3, 'd'=>8, 'e'=>9, 'f'=>10, 'g'=>13);
	my $hash_element_num1 = keys %hash1;
	my $hash_element_num2 = %hash1;

	print '$hash_element_num1 is ', $hash_element_num1, "\n";
	print '$hash_element_num2 is ', $hash_element_num2, "\n";
}

element_number_test();