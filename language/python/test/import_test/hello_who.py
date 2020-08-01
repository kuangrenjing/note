#!/usr/bin/python
# -*- coding: UTF-8 -*-

#who = "mqs"

import sys
import os
#sys.path.append(os.path.dirname(__file__))
print("[hello_who]sys.path is ", sys.path)

#import import_test.who
from import_test import who

print("[hello_who]__name__ is ", __name__)

def hello_who_print():
	print("hello", who.who)