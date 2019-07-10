#!/usr/bin/python
# -*- coding: UTF-8 -*-

#import serial
#import pymysql
#import threading
#import time

import matplotlib.pyplot as plt # plt 用于显示图片
import numpy as np

width = 720
height = 576

def draw_fun():#接收函数
	#接受到的数据保存到文件
	fout = open('d:/mqs/vi_chn_0_720_576_p422_1.yuv', 'rb')
	x = np.fromfile(fout, dtype=np.ubyte)
	#data = fout.read()

	for i in range(0, 829440):
		print(x[i], " ")
		if i%16 == 0:
			print("\n")


	#x = x[0:414720]
	#x = x[414720:829440]

	#x = x.reshape(720, 576)

	#plt.imshow(x, cmap='gray') # 显示灰度图片
	#plt.axis('off') # 不显示坐标轴
	#plt.show()

	#print("data.type() is %s", data.type())
	fout.close()



if __name__== '__main__':
	draw_fun()
