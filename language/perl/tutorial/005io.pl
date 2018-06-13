#!/usr/bin/env perl
use warnings;
use strict;

#perl字符串分为单引号字符串和双引号字符串
#
#	单引号字符串除了单引号和在单引号、反斜杠前的反斜杠，其
#它字符都代表它们本身，要表示单引号和反斜杠需使用反斜杠转
#义,反斜杠只有在单引号或反斜杠之前才表示反斜杠，其它时候也
#只是表示它本身；
#
#	双引号字符串内才能使用各种转义字符，譬如换行符；
my $scale1 = '\'string\' is a single quote mark string in perl\n';
my $scale2 = '\'string\' is a single quote mark string in perl\\n';
print $scale1, "\n";
print $scale2, "\n";
my $scale3 = "\"string\" is a double quote mark string in perl\n";
print $scale3;

#.是perl的字符串连接符
my $scale4 = ". operator is use to join " . "two strings in perl\n";
print $scale4;



while(defined(my $LINE1 = <STDIN>))
{
	print "a input line:", $LINE1;
}


my $term = "kan";
my @term = ("fish", "dog", "bird", ("apple", "orange"));

