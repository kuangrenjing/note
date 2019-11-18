#!/bin/sh

i=0
while [ i -le 10]
do
	ntpd -w -p ntp1.aliyun.com
	echo "return:" $?
done

