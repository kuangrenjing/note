#!/usr/bin/python
# -*- coding: UTF-8 -*-

#列表的赋值是浅拷贝


#[]创建空列表
list1 = []
print("[] will create a list:", list1)

#list()也可以创建空列表
list1 = list()
print("list() will create a list:", list1)

#list()可以把其它类型转化为列表(但参数必须是可迭代的 iterable，整数是不可迭代的)
list1 = list("abc")
print("list('abc') will translate 10 to a list:", list1)


# list1.append("2")
# print("[].append('2') will be ", list1)
# #把字符串分割为列表
# str1="1912/09/01"
# list3=str1.split('/')
# print(str1, ".split('/') will be ", list3)
# str2="1912//09/01"
# list4=str2.split('/')
# print(str2, ".split('/') will be ", list4)
# #extend
# list5=['red', 'blue']
# list6=['black', 'green']
# list7=[]
# list7.extend(list4)
# list7.extend(list5)
# print(list5, ".extend ", list6, " is ", list7)
# #+
# list8=list5+list6
# print(list5, " + ", list6, " is ", list8)
# #insert函数的使用
# list9=["red", "blue", "green"]
# list9.insert(2, "black")
# print("[\"red\", \"blue\", \"green\"] after insert(2, black) will be", list9)
# #使用pop()获取并删除指定位置的元素
# list10=["red", "blue", "black", "green"]
# list11=["red", "blue", "black", "green"]
# str3=list11.pop(2)
# print(list10, ".pop(2) return <", str3, "> result list will be <", list11, ">")
# #list4.remove(1)
# #print("[\"red\", \"blue\", \"black\", \"green\"] after remove(1) will be", list4)