#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import numpy as np
import matplotlib.pyplot as plt
import struct

#print(sys.argv[1])

f = open(sys.argv[1], mode="r", encoding="utf-8")

X = []
Y = []

i = 0
for line in f:
	data = line.split()
	X.append(int(data[0]))
	Y.append(float(data[1]))

f.close()



X = np.array(X)
Y = np.array(Y)

Y /= 0.005859375;

#print(X)
#print(Y)

def linear_regression(x, y):
	N = len(x)
	sumx = sum(x)
	sumy = sum(y)
	sumx2 = sum(x**2)
	sumxy = sum(x*y)

	A = np.mat([[N, sumx], [sumx, sumx2]])
	b = np.array([sumy, sumxy])

	return np.linalg.solve(A, b)

#拟合
a1, a0 = linear_regression(X, Y)
#print("a0 a1 is ", a0, a1)

#四舍五入保留6位小数
a0 = round(a0, 6)
a1 = round(a1, 6)

#python float转16进制参考：https://blog.csdn.net/zhanghui962623727/article/details/84555011
#hex文件格式参考：https://blog.csdn.net/weixin_39752827/article/details/81477686
#flash中写入 波特率 奇偶校验 modbus从地址 无效(0)   a0    a1
#             4字节  1字节     1字节       2字节  4字节  4字节
n = 9600  #波特率
str1 = n.to_bytes(length=4, byteorder='little', signed=False).hex()
n = 0  #无奇偶校验
str2 = n.to_bytes(length=1, byteorder='little', signed=False).hex()
n = 0  #modbus从机地址
str3 = n.to_bytes(length=1, byteorder='little', signed=False).hex()
n = 0  #无效数据
str4 = n.to_bytes(length=2, byteorder='little', signed=False).hex()

str5 = struct.pack("<f", a0).hex()
str6 = struct.pack("<f", a1).hex()

#计算校验字节
strall1 = "10FC0000" + str1 + str2 + str3 + str4 + str5 + str6
b1 = bytes.fromhex(strall1)
b2 = 0
for b in b1:
	b2 += b
b2 = 0x100-b2%0x100
str7 = b2.to_bytes(length=1, byteorder='little', signed=False).hex()

strall2 = ":10FC0000" + str1 + str2 + str3 + str4 + str5 + str6 + str7 + '\n'
#print(strall2)

#把strall2写入到hex文件中去
#比较hex文件的每一行，如果某行开头是":10FC0000"，则替换为strall2，
#如果没有，但找到一行":0400000508000131BD"，在这一行前插入strall2
f = open(sys.argv[2], mode="r", encoding="utf-8")
f2 = open("new.hex", mode="w", encoding="utf-8")

find = 0
for line in f:
	index1 = line.find(":10FC0000")
	index2 = line.find(":0400000508000131BD")
	if(index1 == 0):
		find = 1
		f2.write(strall2)
	elif(index2 == 0 and find == 0):
		f2.write(":020000040801F1\n");
		f2.write(strall2)
		f2.write(line)
	else:
		f2.write(line)

f.close()
f2.close()