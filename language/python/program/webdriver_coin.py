#!/usr/bin/python
# -*- coding: UTF-8 -*-

#https://new.qq.com/rain/a/20201128A061N100
#https://eapply.abchina.com/coin/coin/testCoinRequest1212121?issueid=I067&batchOrder=%201&t=1606812400977
#https://mp.weixin.qq.com/s?__biz=MzI2MjQ3NTQzOQ==&mid=2247483812&idx=1&sn=199498ad0e35177c6ffce942dd02c19f&chksm=ea4bda64dd3c53723f8c651d3a7b25769212cf2bb8f8a1356d0b42f962f0a35b48a99d290302&scene=178&cur_album_id=1390727151775006723#rd

from selenium import webdriver

firefox_obj = webdriver.Firefox()
firefox_obj.get("http://mail.china-cpu.com/webmail7.5/webmail.php?r=site/index")

name_label = firefox_obj.find_element_by_id("username")
name_label.clear()
name_label.send_keys("maquansheng")

name_label = firefox_obj.find_element_by_id("secretkeyshow")
name_label.clear()
name_label.send_keys("1XXdemimi2")

firefox_obj.find_element_by_id("login_submit_btn").click()