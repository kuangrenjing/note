#!/usr/bin/python
# -*- coding: UTF-8 -*-

##旧式格式化方法 string % data

#old1:插入一个数据时，data为基本类型
s1 = "one data %d"%10
print("s1 is ", s1)

#0ld2:插入多个数据时，data为元组
s2="today is %d-%d-%d"%(2019, 4, 16)
print("s2 is ", s2)

#0ld3:域宽：10、对齐：右(默认)、填充：空格(默认,无法显式指定)、字符宽度：数据本身(默认)
s3="%10s's %10d years old, %10f high"%("CFQ", 32, 1.60)
print("s3 is ", s3)

#0ld4:域宽：10、对齐：左、填充：空格(默认,无法显式指定)、字符宽度：数据本身(默认)
s4="%-10s's %-10d years old, %-10f high"%("CFQ", 32, 1.60)
print("s4 is ", s4)

#0ld3:域宽：10、对齐：右(默认)、填充：空格(默认,无法显式指定)、字符宽度：数据本身(默认)
s5="%010s's %010d years old, %10f high"%("CFQ", 32, 1.60)
print("s3 is ", s5)

