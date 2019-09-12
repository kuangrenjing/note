#!/usr/bin/python
# -*- coding: UTF-8 -*-

#http://c.biancheng.net/view/2175.html

str1 = "我爱Python编程";



b1 = bytes(str1,encoding='utf-8');
print("b1 is ", b1);

b2 = bytes(str1,encoding='gbk');
print("b2 is ", b2);

b3 = bytes({1, 2, 3, "ui"});
print("b3 is ", b3);