#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import os

#sys.path.append(os.path.dirname(__file__))

print("sys.path is ", sys.path)
print("__name__ is ", __name__)
#import import_test.hello_who
from import_test.hello_who import hello_who_print


print("dir(hello_who_print) is ", dir(hello_who_print))

print("hello_who_print.__module__ is ", hello_who_print.__module__)

#print("hello_who.__file__ is ", hello_who.__file__)

#print("__file__ is ", __file__)
#print("os.path.dirname(__file__) is ", os.path.dirname(__file__))

hello_who_print()