#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import os

#sys.path.append(os.path.dirname(__file__))

print("sys.path is ", sys.path)

#import import_test.hello_who
from .import_test import hello_who

print("hello_who.__file__ is ", hello_who.__file__)

#print("__file__ is ", __file__)
#print("os.path.dirname(__file__) is ", os.path.dirname(__file__))

hello_who.hello_who_print()