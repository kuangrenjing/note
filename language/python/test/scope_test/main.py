#!/usr/bin/env python3
# coding=utf-8

#data = "this is main data"
'''
仿/usr/local/python3/lib/python3.6/importlib/__init__py
'''

import sys
import child_scope
import family

try:
	import family
except ImportError:
	print("import family thow ImportError")
else:
	print("import family successed")
	family.mqs.name()




