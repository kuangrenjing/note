#!/usr/bin/python
# -*- coding: UTF-8 -*-

import serial
#import pymysql
import threading
import time

x=serial.Serial('COM7',9600)#这是我的串口，测试连接成功，没毛病

def receive_fun():#接收函数
	#接受到的数据保存到文件
	fout = open('d:/马全胜/file_test.txt', 'wt')
	while True:
		time.sleep(0.00001)
		out = ''
		if x.inWaiting() > 0:
			out = x.read(x.inWaiting())
		else:
			continue
		#out += '\r\n'
		ct = time.time()
		local_time = time.localtime(ct)
		data_head = time.strftime("%Y-%m-%d %H:%M:%S", local_time)
		data_secs = (ct - int(ct)) * 1000
		time_stamp = "%s.%03d" % (data_head, data_secs)

		datas =''.join(map(lambda x:('/x' if len(hex(x))>=4 else '/x0')+hex(x)[2:],out))#将数据转成十六进制的形式
		datas = '[' + time_stamp + ']' + datas + '\r\n'
		#print("datas is ", datas)
		fout.write(datas)
	fout.close()



if __name__== '__main__':
	#设置串口
	x.parity='N'
	x.bytesize=8
	x.stopbits=1
	print("serial info is:", x)

	#线程1：不断的去接受数据
	t1 = threading.Thread(target=receive_fun, name="receive")
	t1.start()#开启线程1