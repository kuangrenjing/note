#!/usr/bin/python
# -*- coding: UTF-8 -*-
import struct  #16进制转换浮点型
import os
import sys
import xlwt
import xlrd
#from xlrd import *
 
def learn_to_pack_func():
    ''
    while(1):
        op_id = int(raw_input('please select float to hex(0) or hex to float(1),other value to quit:'))
        if op_id == 0:
            num = float(raw_input('please input the float number:'))
            result = struct.pack('>f',num).encode('hex')
            print result
        elif op_id== 1:
            num =str(raw_input('please input the hex number:'))
            str1= num[2:]
            str2 =struct.unpack('>f',(str1.decode('hex')))
            print str2
        else:
            break
    return 0
 
def read_data_from_excel(filePath,readData):
    ''
    #read data from excel
    bk = xlrd.open_workbook(filePath)
    shxrange = range(bk.nsheets)
    try:
        sh = bk.sheet_by_name('Sheet1')
    except:
        print "no sheet in %s named Sheet1" % fname
    #获取行数
    nrows = sh.nrows
    #获取列数
    ncols = sh.ncols
    #获取数据
    for i in range(0,nrows):
        for j in range(0,ncols):
            readData.append(sh.cell(i,j).value)
    return 0
 
def save_data_to_excel(filePath,writeData):
    ''
    bk = xlwt.Workbook(encoding='utf-8')
    ws = bk.add_sheet('Sheet1',cell_overwrite_ok=False)
 
    for i,row in enumerate(writeData):
        for j,clo in enumerate(row):
            ws.write(i,j,clo)
    bk.save(filePath)
    
def LEEE754Data_Hex_To_Float_Translate():
    ''
    cwd = os.getcwd()
    path = cwd +'\data.xls'
    path_1 = cwd+'\data_1.xls'
    Data_Source = []
    Data_Result = []
    #获取数据
    read_data_from_excel(path,Data_Source)
    #数据转换
    for i in range(len(Data_Source)):
        num =Data_Source[i]
        str1= num[2:]
        str2 =struct.unpack('>f',(str1.decode('hex')))
        Data_Result.append(str2)
    #保存数据
    save_data_to_excel(path_1,Data_Result)
    return 0
    
def main():
    ''
    op_mode =int(raw_input('please select opreation mode(0:auto,1:manual):'))
    if 0 == op_mode:
        LEEE754Data_Hex_To_Float_Translate()
    elif 1 == op_mode:
        learn_to_pack_func()
    else:
        print 'error'
    
if __name__=='__main__':
    main()