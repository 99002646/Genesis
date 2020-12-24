import tkinter as tk
from tkinter import Frame, Button, Canvas
import matplotlib
matplotlib.use('TkAgg')
import numpy as np
import matplotlib.pyplot as plt
from math import pi
import math
import pickle
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
#from matplotlib.backends.backend_tkagg import ( FigureCanvasTkAgg, NavigationToolbar2Tk)
from matplotlib.figure import Figure
from matplotlib.lines import Line2D
import matplotlib.animation as animation
import pylab
from scipy.signal import butter, lfilter
from scipy.signal import freqz
from scipy.ndimage import gaussian_filter1d
import socket
import time
import datetime as dt
import random

from collections import deque

numberconvert = 0
HEADERSIZE =100
numberlist = []
number_list=[]
a=[]
type_of_measurement = ""
typeofelement=""
range2=0
list1=[]
input_volt=0
attenuation_factor=0.014

def convert(x):
    c = (x >> 8) & 0xff
    f = x & 0xff
    return c, f

def butter_bandpass(lowcut, highcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    high = highcut / nyq
    b, a = butter(order, [low, high], btype='band')
    return b, a
 
def butter_bandpass_filter(data, lowcut, highcut, fs, order=5):
    b, a = butter_bandpass(lowcut, highcut, fs, order=order)
    y = lfilter(b, a, data)
    return y

def butter_lowpass(lowcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    b, a = butter(order, [low], btype='low')
    return b, a
 
def butter_lowpass_filter(data, lowcut, fs, order=5):
    b, a = butter_lowpass(lowcut, fs, order = order)
    y = lfilter(b, a, data)
    return y

def generateSignal():
    f=int(signal.get()) 
    lowcut = 40.0
    highcut = 70.0
    o = 3
    type_of_measurement = measurement_choices.get()
    input_volt=int(input_volt_amplitude.get())
    fs=int(sam_fre.get()) #sampling frequency
    f=int(signal.get())#signal frequency
    range2=choices.get()

    amp = 1.414*input_volt 
    T = 1/f
    Ts = 1/fs  
        
    SampleQue = deque() # sample que of 1000, intialize to all zeros
        
        #pop 100 sampls
        # genertae 100 samples
       # for 100

        #add 100 sample

    if type_of_measurement == "Voltage - AC":
        print("Signal Frequency is ",f)
        print("Input Voltage(Amplitude) is ",input_volt)       
        print("Sampling Frequency is ",fs)
        
        #timer = threading.Timer(0.01, generateSignal) 
        #timer.start()

        x = np.arange(fs)
        yout= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs)))) for i in x ]
        yo= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs))))*(1/attenuation_factor) for i in x ]

        adc=[((yo[i]/5)*65536)+(32768) for i in x]
        for i in x:
            op1 = 32768 + butter_bandpass_filter(adc, lowcut, highcut, fs, order=o)

       
    elif type_of_measurement == "Voltage - DC": 
        lowcut = 25
        o = 3
        N = 40000
        Ts=1/fs

        input_volt=int(input_volt_amplitude.get())#----------input from amplitude
        yout = (input_volt + ((0.01*input_volt*np.random.randn(N))))
        ip = (input_volt + ((0.01*input_volt*np.random.randn(N))))*5/range2
        adc=((ip/5)*65536)
        print(yout)

        x = []
        N = fs
        y = []
        def animate(i,x,y):
            x.append(i)
            y.append(input_volt + ((0.01*input_volt*random.randint(0,10))))
            i+=1
            x=x[:fs]
            y=y[:fs]
            ax1.clear()
            ax1.plot(x,y)
            plt.xticks(rotation=45, ha='right')
                
        fig = plt.Figure(figsize=(6,4))
        canvas = FigureCanvasTkAgg(fig, master=root)
        canvas.get_tk_widget().place(x=0, y=190)    
        plot.ani = animation.FuncAnimation(fig, animate, fargs=(x,y),interval=1)
            
        ax1 = fig.add_subplot(111)
        ax1.set_xlabel("Time")
        ax1.set_ylabel("Amplitude")
        line, = ax1.plot(x, np.sin(x))

def plot ():
    input_volt=int(input_volt_amplitude.get())#----------input from amplitude
    fs=int(sam_fre.get())
    
    type_of_measurement = measurement_choices.get()
    range2 = choices.get()
    print("Type of measurement : ",type_of_measurement)
    print("Range is : ",range2)
    numberlist.append(type_of_measurement)
    numberlist.append(str(range2))
    numberlist.append(str(input_volt))

    if type_of_measurement == "Voltage - AC":
        f=int(signal.get()) 
        lowcut = 40.0
        highcut = 70.0
        o = 3
    
        if input_volt<range2:
            print("Signal Frequency is ",f)
            print("Input Voltage(Amplitude) is ",input_volt)       
            print("Sampling Frequency is ",fs)
            
            #Parameters
            amp = 1.414*input_volt       #          (Amplitude)
            T = 1/f
            Ts = 1/fs
            
            x = np.arange(fs)
            yout= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs)))) for i in x ]
            yo= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs))))*(1/attenuation_factor) for i in x ]
                    #Add If condition for AC selection of configurator
            adc=[((yo[i]/5)*65536)+(32768) for i in x]
                
            plt.plot(yout)
            #plt.legend()
            plt.grid()
            plt.show()
            
def reset():
    signal.set(50)
    input_volt_amplitude.set(220)
    #sampling.set(0)
    sam_fre.set(1000)
    measurement_choices.set("Voltage - AC")
    choices.set(230)
    #attenuation.set(0.014)
    #canvas.delete('all')
    #animation.destroy()

def on_option_change(event):
    selected = measurement_choices.get()
    if selected == "Voltage - AC":
        #input_range = {110,230,440,500}
        rangeL = tk.OptionMenu(root,choices, *ac_range)
        rangeL.config(bg = "LightYellow2")
        rangeL.configure(width=15)
        rangeL.place(x=250, y=35)
        choices.set(230)

    elif selected == "Voltage - DC":
        #input_range = {10,24,48}
        rangeL = tk.OptionMenu(root,choices, *dc_range)
        rangeL.config(bg = "LightYellow2")
        rangeL.configure(width=15)
        rangeL.place(x=250, y=35)
        choices.set(10)

#Execution starts here
root = tk.Tk()
root.title("Configurator")
title_bar = Frame(root, bg='brown', relief='raised', bd=2)
title_bar.pack()
root.geometry("600x700")
root.configure(bg='#FFFFFF')

#Variable data types
measurement_choices = tk.StringVar()
ac_choices = tk.IntVar()
dc_choices = tk.IntVar()
choices=tk.IntVar()

#Assigning values
measurement_type = {"Voltage - AC", "Voltage - DC"}

#Label - Type of Measurement
type_label=tk.Label(root,text="Type of Measurement",bg='White',fg='black',font='Helvetica 8 bold')
type_label.place(x=50, y=10)
measurement_choices.set("Voltage - AC")

#Option Menu to select Measurement type
measur_type = tk.OptionMenu(root,measurement_choices, *measurement_type, command=on_option_change)
measur_type.config(bg = "LightYellow2")
measur_type.configure(width=15)
measur_type.place(x=50, y=35)

range_label=tk.Label(root,text="Range",bg='White',fg='black',font='Helvetica 8 bold')
range_label.place(x=250, y=10)
#measurement_choices.set(230)

ac_range ={110,230,440,500}
dc_range = {10,24,48}
input_range = {110,230,440,500}

selected = measurement_choices.get()
if selected ==  "Voltage - AC":
    rangeL = tk.OptionMenu(root,choices, *ac_range)
    rangeL.config(bg = "LightYellow2")
    rangeL.configure(width=15)
    rangeL.place(x=250, y=35)
    choices.set(230)
if selected == "Voltage - DC":
    rangeL = tk.OptionMenu(root,choices, *dc_range)
    rangeL.config(bg = "LightYellow2")
    rangeL.configure(width=15)
    rangeL.place(x=250, y=35)
    choices.set(230)

#unit
unit_range_label = tk.Label(text="Unit",bg='White',fg='black',font='Helvetica 8 bold')
unit_range_label.place(x=465, y=10)

unit_range_label1 = tk.Label(text="Volts",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)
unit_range_label1.place(x=430, y=40)

#Signal Frequency
signal_freq_label = tk.Label(text="Signal Frequency",bg='White',fg='black',font='Helvetica 8 bold')
#signal_freq_label.place(x=30, y=100)
signal_freq_label.place(x=290, y=100)

signal = tk.DoubleVar()
signal_freq_entry = tk.Entry(root, width = 15, textvariable = signal)
#signal_freq_entry.place(x=30, y=130)
signal_freq_entry.place(x=290, y=130)

#Amplitude
amplitude_label = tk.Label(text="Input Voltage",bg='White',fg='black',font='Helvetica 8 bold')
amplitude_label.place(x=160, y=100)

input_volt_amplitude = tk.DoubleVar()
amplitude_entry = tk.Entry(root, width = 15, textvariable = input_volt_amplitude)
amplitude_entry.place(x=160, y=130)

#Sampling Frequency
sampling_freq_label = tk.Label(text="Sampling Frequency",bg='White',fg='black',font='Helvetica 8 bold')
#sampling_freq_label.place(x=290, y=100)
sampling_freq_label.place(x=430, y=100)

sam_fre = tk.DoubleVar()
sampling_freq_entry = tk.Label(text="12",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = sam_fre)
sampling_freq_entry.place(x=430, y=130)
sam_fre.set(1000)

#Attenuation Factor
attenuation_factor_label = tk.Label(text="Attenuation Factor",bg='White',fg='black',font='Helvetica 8 bold',width=15)
#attenuation_factor_label.place(x=430, y=100)
attenuation_factor_label.place(x=30, y=100)

attenuation = tk.DoubleVar()
attenuation_factor_value_label = tk.Label(text="",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = attenuation)
#attenuation_factor_value_label.place(x=430, y=130)
attenuation_factor_value_label.place(x=30, y=130)
attenuation.set(0.014)

#Draw button
graph_button = tk.Button(root, text="Execute",bg='brown',fg='white', command=plot)
graph_button.place(x=45, y=160)

#Reset button
reset_button = tk.Button(root,text="Reset", bg='brown',fg='white', command=reset)
reset_button.place(x=250, y=160)

root.mainloop()
