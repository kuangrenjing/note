#!/usr/bin/python
# -*- coding: UTF-8 -*-

#文件操作

txt = '''陈斐倩
今天你真漂亮2'''

fout = open('e:/program/python/file_test.txt', 'w+t')
fout.write(txt)
fout.close()