# -*- coding: utf-8 -*-
"""
Created on Sat Oct 23 21:54:51 2021

@author: ssabi
"""


import serial
import time

string = input('Enter text to transmit\n')
string +='\r'
print(string)

serialcomm = serial.Serial('/dev/ttyACM0',9600)
serialcomm.timeout = 1

while True:
    s = input("1->transmit,0->exit ").strip()
    if s == '0':
        print("Exit")
        break
    serialcomm.write(string.encode())
    time.sleep(0.5)

#print(serialcomm.read_until(b'\r').decode('utf-8'))
serialcomm.close()