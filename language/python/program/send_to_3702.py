#!/usr/bin/python
# -*- coding: UTF-8 -*-
import socket
import time



s = socket.socket()
s.connect(("192.168.15.28", 3702));
s.send(b"hello world!")




s.close()