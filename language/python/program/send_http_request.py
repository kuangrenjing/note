#!/usr/bin/python
# -*- coding: UTF-8 -*-
import socket
import time

strSend1 = "OPTIONS rtsp://192.168.15.27:554/Streaming RTSP/1.0\r\n\
CSeq: 2\r\n\
User-Agent: LIVE555 Streaming Media v2013.02.11\r\n\r\n"

##
# @不支持的方法测试
##
strSend2 = "OPTIONST rtsp://192.168.15.27:554/Streaming RTSP/1.0\r\n\
CSeq: 2\r\n\
Content-length: 12\r\n\
User-Agent: LIVE555 Streaming Media v2013.02.11\r\n\r\n\
hello world!"

##
# @测试版本：版本号用字母
##
strSend3 = "OPTIONS rtsp://192.168.15.27:554/Streaming RTSP/a.2\r\n\
CSeq: 2\r\n\
Content-length: 12\r\n\
User-Agent: LIVE555 Streaming Media v2013.02.11\r\n\r\n\
hello world!"

##
# @测试带负载
##
strSend4 = "OPTIONS rtsp://192.168.15.27:554/Streaming RTSP/1.0\r\n\
CSeq: 2\r\n\
Content-length: 12\r\n\
User-Agent: LIVE555 Streaming Media v2013.02.11\r\n\r\n\
hello world!"

##
# @测试无负载时带垃圾
##

##
# @测试有负载时带垃圾
##


##
# @测试websocket
##
strSend7 = "GET / HTTP/1.1\r\n\
Upgrade: websocket\r\n\
Connection: Upgrade\r\n\
Host: example.com\r\n\
Origin: http://example.com\r\n\
Sec-WebSocket-Key: sN9cRrP/n9NdMgdcy2VJFQ==\r\n\
Sec-WebSocket-Version: 13\r\n\r\n"

strSend = strSend7

bSend = bytes(strSend, encoding="utf-8")
iSendLen = len(bSend)
i = 0
step = 16

s = socket.socket()
s.connect(("192.168.15.27", 554));

print("iSendLen is ", iSendLen)

##
# @用于分包测试
##
while(i < iSendLen):
	bSend1 = bSend[i:(i+step if i+step<iSendLen else iSendLen)]
	i = i+step
	print("i is ", i)
	strSend1 = bSend1.decode('utf-8')
	print("strSend1 is ", strSend1)
	s.send(bSend1)
	time.sleep(1)

#s.send(bSend)



strRecv = s.recv(1024).decode('utf-8')
print("strRecv is ", strRecv)


while 1:
	time.sleep(3)


s.close()