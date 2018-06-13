#!/usr/bin/env perl
use strict;
use warnings;
use utf8;

open my $fh, '<', '/home/mqs/s.log' or die $!;
while (<$fh>) { # 读取一行到变量 $_ 中
	my $line = <$fh>
	print $line; #将读了那行打印出来
}
close $fh;