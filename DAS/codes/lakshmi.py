import numpy as np
import time
from math import pi
x = np.arange(1000)
attenuation_factor = 0.014
list_one=[]
k=0
i =0
j = 0
input_volt=230
amp = 1.414*input_volt 
f = 10 
fs = 1000 
T = 1/f
Ts = 1/fs
temp=[]
def data(j,k):
    while k < j:
        list_one.insert(k,x[k])
        k = k+1
def repeat(): 
    while True:
        count = data(j,k)
        time.sleep(0.06)
        j=j+10
    if len(list_one)==1000:
        temp.extend(list_one)
        list_one.clear()
        break