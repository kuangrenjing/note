#!/usr/bin/env bash

<<COMMENT
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
资料：
	https://www.linuxidc.com/Linux/2017-08/146494.htm
COMMENT

<<COMMENT
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、linux是怎么启动起来的

	操作系统的启动分为两个阶段：引导boot和启动startup。引导阶段开始于打开电源开关，结束
于内核初始化完成和 systemd 进程成功运行。启动阶段接管了剩余工作，直到操作系统进入可操作
状态。

总体来说，Linux 的开机引导和启动过程是相当容易理解，下文将分节对于不同步骤进行详细说明。
	BIOS上电自检（POST）
	引导装载程序 (GRUB2)
	内核初始化
	启动 systemd，其是所有进程之父。

	BIOS 上电自检确认硬件的基本功能正常，然后产生一个 BIOS 中断 INT 13H，该中断指向某
个接入的可引导设备的引导扇区。它所找到的包含有效的引导记录的第一个引导扇区将被装载到内存
中，并且控制权也将从引导扇区转移到此段代码。

	引导扇区是引导加载器真正的第一阶段。大多数 Linux 发行版本使用的引导加载器有三种：
GRUB、GRUB2 和 LILO。GRUB2 是最新的，也是相对于其他老的同类程序使用最广泛的。

	引导扇区通常位于可引导设备的第0扇区，此处通常又称为MBR(主引导记录Master Boot 
Record)，引导代码(即阶段1代码)必须非常小，因为它必须连同分区表放到硬盘的第一个512字节
的扇区中。 在传统的常规MBR中，引导代码实际所占用的空间大小为446字节。这个阶段1的446字节
的文件通常被叫做引导镜像(boot.img)，其中不包含设备的分区信息，分区是一般单独添加到引导
记录中。

	由于引导记录必须非常的小，它不可能非常智能，且不能理解文件系统结构。因此阶段1的唯一
功能就是定位并加载阶段1.5的代码。为了完成此任务，阶段1.5的代码必须位于引导记录与设备第一
个分区之间的位置。在加载阶段1.5代码进入内存后，控制权将由阶段1转移到阶段1.5。

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	阶段1.5代码core.img位于硬盘第1扇区和第62扇区之间(最大62*512=31744字节)。core.img
包含一些通用的文件系统驱动程序，如标准的EXT和其它的Linux文件系统，如FAT和NTFS等。阶段1.5
的功能是开始执行存放阶段2文件的/boot文件系统的驱动程序，并加载相关的驱动程序。

	未完待续
COMMENT

<<COMMENT
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
2、文件系统、挂载点、目录树、VFS
	grub运行时应该还没有VFS、挂载点的支持
COMMENT

<<COMMENT
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
2、rootfs
根文件系统之外的其他文件要想能够被访问，都必须通过“关联”至根文件系统上的某个目录来实现，此关联操作即为“挂载”，此目录即为“挂载点”,解除此关联关系的过程称之为“卸载”


vfw
COMMENT