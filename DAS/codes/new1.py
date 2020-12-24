
import socket
import numpy as np
import matplotlib.pyplot as plt
import math
from scipy.ndimage import gaussian_filter1d
import pickle
import tkinter as tk
from tkinter import Frame, Button, Canvas
from matplotlib.lines import Line2D
import matplotlib.animation as animation
from math import pi
from scipy.signal import butter, lfilter
from scipy.signal import freqz
from numpy.compat.py3k import long
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


def plot():
    iterDC = 0
    iterAC = 0
    maxval = len(arr)
    x = np.arange(maxval, step = 1)
    if (type_of_measurement == 'Voltage - DC'):
        while(iterDC < maxval ):
            opc.append((lis[iterDC]/65536)*Range)
            iterDC = iterDC+1
    elif (type_of_measurement == 'Voltage - AC'):
        while(iterAC < maxval ):
            opc.append(((lis[iterAC]-32768)/65536)*(Range)*2.5*1.26)
            iterAC = iterAC+1

    InVolt_label_value1.set(input_volt)
    range_label_value1.set(Range)
    mt1['text']=type_of_measurement
    u1['text']="Volts"
    attenuation_value.set(attenuation_factor)

    fig = plt.Figure(figsize=(6,5))
    #plt.bar(x=x, height=y)
    plt.xticks(x, rotation=90)
    canvas = FigureCanvasTkAgg(fig, master=root)
    canvas.draw()
    canvas.get_tk_widget().place(x=0, y=200)
    ax1 = fig.add_subplot(111)
    ax1.set_xlabel("Time")
    ax1.set_ylabel("Amplitude")
    line, = ax1.plot(x, np.sin(x))

def reset():
    InVolt_label_value1.set(0)
    u1['text']=" "
    mt1['text']=" "
    range_label_value1.set(0)
    attenuation_value.set(0)

def exitWindow():
    root.destroy()

HOST = socket.gethostbyname(socket.gethostname())
PORT = 7874  
HEADERSIZE = 10  
lis= []  
lis2=[]  
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    data = s.recv(640016)
    data = data.decode('utf-8')
    data = eval(data)
    type_of_measurement = data[0]
    Range = int(data[1])
    input_volt=float(data[2])
    attenuation_factor=float(data[3])

    print(f"type_of_measurement:{type_of_measurement}")
    print(f"Range:{Range}")
    print(f"attenuation_factor:{attenuation_factor}")
    print(f"input_volt:{input_volt}")
    
    #opc = []
    del data[0:4]
    for i in data :
        if not i:
            break 
        j=(i[0]<<8)+i[1]
        lis.append(j) 
    opc = []
    arr = np.array(lis)
    #print(arr)
    iterDC = 0
    iterAC = 0
    maxval = len(arr)
    x = np.arange(maxval, step = 1)
    '''
    if (type_of_measurement == 'Voltage - DC'):
        while(iterDC < maxval ):
            opc.append((lis[iterDC]/65536)*Range)
            iterDC = iterDC+1
    if (type_of_measurement == 'Voltage - AC'):
        while(iterAC < maxval ):
            opc.append(((lis[iterAC]-32768)/65536)*(Range)*2.5*1.26)
            iterAC = iterAC+1
    '''
    #opiter = 0
    #opc_list = opc.tolist()
    #for opiter in x:
        #print(opc_list[opiter])
    
        #opiter = opiter + 1
    #plt.plot(x, opc, color='green', linestyle='dashed', linewidth = 3, marker='o', markerfacecolor='blue', markersize=5) 
    #plt.grid()
    #plt.show()


#Execution starts here
root = tk.Tk()
root.title("Display")
title_bar = Frame(root, bg='brown', relief='raised', bd=2)
title_bar.pack()
root.geometry("600x800")
root.configure(bg='#FFFFFF')

#Variable data types
InVolt_label_value1 = tk.DoubleVar()
unit_label_value1 = tk.StringVar()
mtype_label_value1 = tk.StringVar()
range_label_value1 = tk.DoubleVar()
attenuation_value = tk.DoubleVar()


#Label - Measurement Calculation
iv=tk.Label(root,text="Input Voltage",bg='White',fg='black',font='Helvetica 8 bold')
iv.place(x=35, y=20)
#Measurement Calculation value
mCalc_label_value = tk.Label(text="",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = InVolt_label_value1)
mCalc_label_value.place(x=50, y=40)

#Unit
u = tk.Label(text="Unit",bg='White',fg='black',font='Helvetica 8 bold')
u.place(x=200,y=20)
#Unit value
u1 = tk.Label(text="",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)
u1.place(x=200, y=40)

#Measurement Type
mt = tk.Label(text="Measurement Type",bg='White',fg='black',font='Helvetica 8 bold',width=15)
mt.place(x=50, y=90)
#Measurement Type value
mt1 = tk.Label(text="",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)
mt1.place(x=50, y=120)

#Range
r = tk.Label(text="Range",bg='White',fg='black',font='Helvetica 8 bold',width=15)
r.place(x=200, y=90)
#Range value
r1 = tk.Label(text="",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = range_label_value1)
r1.place(x=200, y=120)

#Range
a = tk.Label(text="Attenuation factor",bg='White',fg='black',font='Helvetica 8 bold',width=15)
a.place(x=360, y=90)
#Range value
a1 = tk.Label(text="",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = attenuation_value)
a1.place(x=355, y=120)

#Draw button
graph_button = tk.Button(root, text="Execute",bg='brown',fg='white',width=10, command=plot)
graph_button.place(x=50, y=170)

#Reset button
reset_button = tk.Button(root,text="Reset", bg='brown',fg='white',width=10, command=reset)
reset_button.place(x=400, y=170)
#reset_button.place(x=225, y=170)
'''
#Exit button
exit_button = tk.Button(root,text="Exit", bg='brown',fg='white',width=10, command=exitWindow)
exit_button.place(x=400, y=170)
'''
root.mainloop()