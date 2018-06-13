#!/usr/bin/env bash

<<COMMENT
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、内核版本信息
	/proc/version这个是内核导出的版本信息(/proc下的文件都是虚拟文件)，是只读的，不能
写。uname命令访问这个文件，具体用法可以"uname --help"查看。
COMMENT


<<COMMENT
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
2、发行版本信息
	不同的发行版查看方法不相同

	发行版基本都提供了/etc/issue文件，但不一定能准确获得结果。

	redhat: /etc/redhat-release
	centos: /etc/centos-release
COMMENT