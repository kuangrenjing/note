#!/usr/bin/python
# -*- coding: UTF-8 -*-

##旧式格式化方法 string % data

#old1:插入一个数据时，data为基本类型
os1 = "one data %d"%10
print("os1 is ", os1)

#0ld2:插入多个数据时，data为元组
os2="today is %d-%d-%d"%(2019, 4, 16)
print("os2 is ", os2)

#0ld3:域宽：10、对齐：右(默认)、字符宽度：数据本身(默认)
os3="%10s's %10d years old, %10f high"%("CFQ", 32, 1.60)
print("os3 is ", os3)

#0ld4:域宽：10、对齐：左、字符宽度：数据本身(默认)
os4="%-10s's %-10d years old, %-10f high"%("CFQ", 32, 1.60)
print("os4 is ", os4)

#0ld5:域宽：10、对齐：右(默认)、字符宽度：1(目标字符串大于此值则截断，目标整数大于此值则忽略此值，域宽亦如此)
os5="%10.1s's %10.1d years old, %10.1f high"%("CFQ", 32, 1.60)
print("os5 is ", os5)

#0ld6:域宽：10、对齐：右(默认)、字符宽度：5(目标字符串大于此值则忽略此值，目标整数小于此值则拿0填充，域宽亦如此)
os6="%10.5s's %10.5d years old, %10.5f high"%("CFQ", 32, 1.60)
print("os6 is ", os6)

#new1
ns1="{}".format(42)
print("ns1 is ", ns1)

#new2
ns2="{1} is {0} years old".format(30, "CFQ")
print("ns2 is ", ns2)

#new3:格式串中引用函数参数名(python函数用法而已)
ns3='{name} is {age} years old'.format(age=30, name="CFQ")
print('ns3 is ', ns3)

#new4:指定格式-整数、浮点数、字符串
ns4='{0:s} is {1:d} years old, {2:f} high'.format('CFQ', 30, 1.60)
print('ns4 is ', ns4)

#new5:域宽：10、对齐：字符串左，数字右(默认)、填充：空格(默认)、精度/字符宽度：数据本身(默认)
ns5='{0:10s} is {1:10d} years old, {2:10f} high'.format('CFQ', 30, 1.60)
print('ns5 is ', ns5)

#new6:域宽：10、对齐：居中、填充：!、精度/字符宽度：4(整数不能指定精度)
ns6='{0:!^10.4s} is {1:!^10d} years old, {2:!^10.4f} high'.format('CFQ', 30, 1.60)
print('ns6 is ', ns6)

#new7:目标整数字符个数大于域宽时，域宽指定无效（整数不能指定精度）
ns7='1234567.{{:6d}} is {:6d}'.format(1234567)
print("ns7 is ", ns7)
