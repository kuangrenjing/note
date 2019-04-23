#!/usr/bin/python
# -*- coding: UTF-8 -*-

#列表的赋值是浅拷贝


#[]创建空列表
list1 = []
print("[] will create a list: <", list1, ">")

#list()也可以创建空列表
list1 = list()
print("list() will create a list: <", list1, ">")

#list()可以把其它类型转化为列表(但参数必须是可迭代类型(iterable)，整数不是可迭代类型)
list1 = list("abc")
print("list('abc') will translate < abc > to a list: <", list1, ">")

#list string.split(separator) 分割符可以是多个字符
str1 = "1912ab04ab01"
sep  = "ab"
list1 = str1.split(sep)
print(str1, " separate with <", sep, "> will return <", list1, ">")

#list string.split(separator) 分隔符遵循最长搜索
str1 = "adminabadminabyes"
sep  = "ab"
list1 = str1.split(sep)
print(str1, " separate with <", sep, "> will return <", list1, ">")

#list[offset]获取/修改列表元素，-> offset从0开始, <- offset从-1开始，offset必须在范围内
list1 = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
print(list1, "[0] is <", list1[0], ">, [-1] is <", list1[-1], ">")

#切片：list[begin:end:step]，范围：[begin, end)
list1 = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
list2 = list1[1:3]
list3 = list1[1:5:2]
print(list1, "[1:3] is <", list2, ">")
print(list1, "[1:5:2] is <", list3, ">")

#list.append(元素) 元素也可以是列表，注意与extend区别
list1=[]
list1.append("Monday")
print("[].append('Monday') will be <", list1, ">")

#list.extend(列表)
list1 = ["Monday", "Tuesday"]
list2 = list1.copy()
list3 = list1.copy()

list4 = ["Wednesday"]
list2.extend(list3)
print(list1, ".extend(", list4, ") will be <", list2, ">")

list3+=list4
print(list1, "+=", list4, " will be <", list3, ">")

#list.insert(元素) 在旧索引之前插入元素，越界不产生异常，事实上，要插到最后必须越界
list1 = ["Monday", "Wednesday"]
list2 = list1.copy()
list3 = list1.copy()

list2.insert(-1, "Tuesday")
print(list1, "insert(-1, 'Wednesday') will be <", list2, ">")

list3.insert(1, "Tuesday")
print(list1, "insert(1, 'Wednesday') will be <", list3, ">")

#del删除指定位置元素


#list.remove(value) 从前到后搜索，删除列表中第一个具有指定值的元素
list1 = ["Monday", "ha", "Tuesday", "ha", "Wednesday"]
list2 = list1.copy()
list2.remove("ha")
print(list1, ".remove('ha') will be <", list2, ">")

#list.pop(index) 获取并删除指定位置的元素
list1 = ["Monday", "ha", "Tuesday", "ha", "Wednesday"]
list2 = list1.copy()
str1 = list2.pop(1)
print(list1, ".pop(1) will be <", list2, "> and return <", str1, ">")

#list.append()  list.pop(0) 可以模拟FIFO

#list.index(value) 从前向后搜索，返回列表中第一个具有指定值的元素的索引，没有指定值的元素会引发异常
list1 = ["Monday", "ha", "Tuesday", "ha", "Wednesday"]
print(list1, ".index('ha') is <", list1.index('ha'), ">")

#in是python关键字
list1 = ["Monday", "ha", "Tuesday", "ha", "Wednesday"]
print(list1, "has 'ha': <", 'ha' in list1, ">")

#list.count()统计特定值出现的次数
list1 = ["Monday", "ha", "Tuesday", "ha", "Wednesday"]
print("ha appear <", list1.count('ha'), "> times in ", list1)

#list.sort()函数 数字序、字母序、星期序
list1 = ["Monday", "ha", "Tuesday", "ja", "Wednesday"]
list2 = list1.copy()
list2.sort()
print(list1, ".sort() will be: <", list2, ">")

#sorted内置函数
list1 = ["Monday", "ha", "Tuesday", "ha", "Wednesday"]
list2 = sorted(list1)
print("sorted(", list1, ") will be: <", list2, ">")


#list.len()返回元素个数
list1 = [["Monday", "ha"], "Tuesday", "ha", "Wednesday"]
print("len(", list1, ") return <", len(list1), ">")


#注意= 与list.copy()的区别



#解包
