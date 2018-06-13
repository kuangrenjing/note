=pod
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、注释
	单行注释： 行内从#开始的部分都是注释
	多行注释：
		最常用的方法是使用 POD(Plain Old Documentations) 来进行多行注释。方法如下:
		=pod
		codes to comment 
		=cut
		注意： 与单行注释不同，=需是行首字符
=cut

=pod
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
2、模块搜寻路径：
	Perl模块搜索路径由PERLLIB环境变量设置
	perl -V 中@INC 变量就是当前环境中PERL模块的默认搜索路径
=cut

=pod
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
3、lockfile
=cut

=pod
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
4、cpan、CPAN.pm

CPAN.pm官网：
	http://search.cpan.org/~andk/CPAN-2.16/lib/CPAN.pm#CONFIGURATION

CPAN.pm用于安装CPAN提供的模块，可以认为CPAN.pm是CPAN的客户端。

CPAN.pm两种用法：
	perl -MCPAN -e shell
	cpan

CPAN.pm配置
	CPAN.pm在使用前需要配置，配置文件为CPAN/Config.pm，交互式配置后会提醒：
Please remember to call 'o conf commit' to make the config permanent!
这时需运行"o conf commit"保存配置

cpan脚本：
	cpan -h可以查看这个脚本的帮助
=cut

=pod
5、@INC、 %INC、 require、 use、 do

@INC:
	保存的是perl模块可能存储的路径。

%INC:
	保存的是各个模块完整路径，通过搜索@INC得来。

require:
use:
do:
=cut


=pod
perl标识符：
	Perl标识符是用户编程时使用的名字，在程序中使用的变量名，常量名，函数名，语句块名等统称为标识符。 
		标识符组成单元：英文字母（a~z，A~Z），数字（0~9）和下划线（_）。
		标识符由英文字母或下划线开头。
		标识符区分大小写，$runoob 与 $Runoob 表示两个不同变量。

=cut


