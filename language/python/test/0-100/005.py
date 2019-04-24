#!/usr/bin/python
# -*- coding: UTF-8 -*-

#{}创建空字典
print("---create test---")
dict1 = {}
print("{} will create a dict: <", dict1, ">")

#dict()也可以创建空字典
dict1 = dict()
print("list() will create a list: <", dict1, ">")
print("\r\n")

#dict(包含双值子序列的序列)
print("---translate test---")
list1 = ["ab", "cd"]
dict1 = dict(list1)
print("dict(", list1, ") will be <", dict1, ">")

list1 = [['a', 'b'], ['c', 'd']]
dict1 = dict(list1)
print("dict(", list1, ") will be <", dict1, ">")

list1 = (['a', 'b'], ['c', 'd'])
dict1 = dict(list1)
print("dict(", list1, ") will be <", dict1, ">")

list1 = [('a', 'b'), ('c', 'd')]
dict1 = dict(list1)
print("dict(", list1, ") will be <", dict1, ">")
print("\r\n")

#dict[key]增、改、查元素
print("---dict[key] test---")
dict1 = {"mqs":"man", "cfq":"female"}
dict2 = dict1.copy()
dict2['myy'] = 'female'
print(dict1, "['cfq'] is <", dict1['cfq'], ">")
print(dict1, "after dict['myy'] = 'female' will be <", dict2, ">")

dict3 = dict2.copy()
dict3['cfq'] = 'man'
print(dict2, "after dict['cfq'] = 'man' will be <", dict3, ">")
print("\r\n")

#dict.update(dict)合并字典
print("---combine two dicts test---")
dict1 = {'mqs':'man', 'cfq':'female'}
dict2 = {'myy':'female'}
dict3 = dict1.copy()
dict3.update(dict2)
print(dict1, ".update(", dict2, ") will be <", dict3, ">")
print("\r\n")

#del dict[key]删元素
print("---delete dict's element test---")
dict1 = {'mqs':'man', 'cfq':'female', 'myy':'female'}
dict2 = dict1.copy()
del dict2['myy']
print("del ", dict1, "['myy'] will be <", dict2, ">")
print("\r\n")

#dict.clear()清除所有元素
print("---clear dict's all elements test---")
dict1 = {'mqs':'man', 'cfq':'female', 'myy':'female'}
dict2 = dict1.copy()
dict2.clear()
print(dict1, ".clear() will be <", dict2, ">")
print("\r\n")

#key in dict判断字典书否存在某个键
print("---in test---")
dict1 = {'mqs':'man', 'cfq':'female', 'myy':'female'}
bIn = 'mqs' in dict1
print("mqs in ", dict1, "? :<", bIn, ">")
print("\r\n")

#dict.keys()获取所有键 dict_keys类
print("---dict.keys() test---")
dict1 = {'mqs':'man', 'cfq':'female', 'myy':'female'}
list1 = dict1.keys()
print(dict1, ".keys() is: <", list1, ">")
print("\r\n")

#dict.values()获取所有值dict_values类
print("---dict.values() test---")
dict1 = {'mqs':'man', 'cfq':'female', 'myy':'female'}
list1 = dict1.values()
print(dict1, ".values() is: <", list1, ">", "type is", type(list1))
print("\r\n")

#dict.items()获取所有元素dict_items类
print("---dict.items test---")
dict1 = {'mqs':'man', 'cfq':'female', 'myy':'female'}
list1 = dict1.items()
print(dict1, ".items() is: <", list1, ">")
print("\r\n")

#len()获取元素个数？
print("---len(dict) test---")
dict1 = {'mqs':'man', 'cfq':'female', 'myy':'female'}
len1 = len(dict1)
print(dict1, "'s lens is: <", len1, ">")
print("\r\n")

#=赋值
#dict.copy()拷贝