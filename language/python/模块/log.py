#!/user/bin/env python
# -*- coding: utf-8 -*-
import threading
import time
import logging
from logging.handlers import TimedRotatingFileHandler


log = logging.getLogger()
file_name = "./test.log"
logformatter = logging.Formatter('[%(asctime)s-%(levelname)s]%(message)s')
loghandle = TimedRotatingFileHandler(file_name, 'midnight', 1, 2)
loghandle.setFormatter(logformatter)
loghandle.suffix = '%Y%m%d'
log.addHandler(loghandle)
log.setLevel(logging.INFO)


def serial_logging():
	while True:
		log.info("init successful")
		time.sleep(0.4)


if __name__ == '__main__':
	#线程1：不断的去接受数据
	t1 = threading.Thread(target=serial_logging, name="serial_logging")
	t1.start()#开启线程1