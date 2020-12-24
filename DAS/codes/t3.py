from tkinter import *
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

root = Tk()
root.title("Configurator")
root.geometry("600x700")
root.configure(bg='#FFFFFF')

#Variable data types
user_input = StringVar()
measurement_choices = StringVar()
ac_choices = IntVar()
dc_choices = IntVar()
choices=IntVar()

InVolt_label_value1 = DoubleVar()
unit_label_value1 = StringVar()
m_type = StringVar()
mtype_label_value1 = StringVar()
range_label_value1 = DoubleVar()
attenuation_value = DoubleVar()

type_of_measurement = ""
typeofelement=""
range2=0
list1=[]
input_volt=0
attenuation_factor=0.014

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

def on_option_change(event):
    selected = measurement_choices.get()
    if selected == "Voltage - AC":
        #input_range = {110,230,440,500}
        rangeL = OptionMenu(root,choices, *ac_range)
        rangeL.config(bg = "LightYellow2")
        rangeL.configure(width=15)
        rangeL.place(x=250, y=35)
        choices.set(230)

    elif selected == "Voltage - DC":
        #input_range = {10,24,48}
        rangeL = OptionMenu(root,choices, *dc_range)
        rangeL.config(bg = "LightYellow2")
        rangeL.configure(width=15)
        rangeL.place(x=250, y=35)
        choices.set(10)

def reset():
    signal.set(50)
    input_volt_amplitude.set(220)
    sam_fre.set(1000)
    measurement_choices.set("Voltage - AC")
    choices.set(230)
    attenuation.set(0.014)

def generateInputSignal():
    input_volt=int(input_volt_amplitude.get())#----------input from amplitude
    fs=int(sam_fre.get())
    #range2=440 
    #input_volt=230#-------------input from amplitude
    type_of_measurement = measurement_choices.get()
    range2 = choices.get()
    print("Type of measurement : ",type_of_measurement)
    print("Range is : ",range2)

    if type_of_measurement == "Voltage - AC":
        f=int(signal.get()) 
        lowcut = 40.0
        highcut = 70.0
        o = 3
    
        if input_volt<range2:
            print("Signal Frequency is ",f)
            print("Input Voltage(Amplitude) is ",input_volt)       
            print("Sampling Frequency is ",fs)
            #print("Range is ",range2)
            
            #Parameters
            amp = 1.414*input_volt       #          (Amplitude)
            T = 1/f
            Ts = 1/fs
            harmonic_amp1=0.05*amp
            harmonic_amp2=0.05*amp

            continous  = True

            fig = plt.Figure()
            x = np.arange(fs)

            yout= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs)))) for i in x ]
            yo= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs))))*(1/attenuation_factor) for i in x ]
            adc=[((yo[i]/5)*65536)+(32768) for i in x]
            for i in x:

                op1 = 32768 + butter_bandpass_filter(adc, lowcut, highcut, fs, order=o)

            class aScope(object):
                def __init__(self, ax, maxt=2*T, dt=Ts):
                    self.ax = ax
                    self.dt = dt
                    self.maxt = maxt
                    self.tdata = [0]
                    self.ydata = [0]
                    self.line = Line2D(self.tdata, self.ydata)
                    self.ax.add_line(self.line)
                    self.ax.set_ylim(-350,350)
                    self.ax.set_xlim(0, self.maxt)
            
                def aupdate(self, y):
                    lastt = self.tdata[-1]
                    if continous :
                        if lastt > self.tdata[0] + self.maxt:
                            self.ax.set_xlim(lastt-self.maxt, lastt)
            
                    t = self.tdata[-1] + self.dt
                    self.tdata.append(t)
                    self.ydata.append(y)
                    self.line.set_data(self.tdata, self.ydata)
                    return self.line,
            
            def sineEmitter():
                for i in x:
                    yield math.ceil(yout[i])

            fig = plt.Figure(figsize=(6,4))
            canvas = FigureCanvasTkAgg(fig, master=root)
            canvas.get_tk_widget().place(x=0, y=190)
            ax1 = fig.add_subplot(111)
            ax1.set_xlabel("Time")
            ax1.set_ylabel("Amplitude")
            scope = aScope(ax1)
   
            # pass a generator in "sineEmitter" to produce data for the update func
            generateInputSignal.ani = animation.FuncAnimation(fig, scope.aupdate, sineEmitter, interval=10,blit=True)
        else:
            print("Signal Frequency is ",f)
            print("Input Voltage(Amplitude) is ",input_volt)       
            print("Sampling Frequency is ",fs)

            #Parameters
            amp = 1.414*input_volt       #          (Amplitude)
            T = 1/f
            Ts = 1/fs
            harmonic_amp1=0.05*amp
            harmonic_amp2=0.05*amp

            continous  = True

            fig = plt.Figure()
            x = np.arange(fs)
           
            yout= [ 0 for i in x ]
            yo= [ 0 for i in x ]
                    
            adc=[((yo[i]/5)*65536)+(32768) for i in x]
            for i in x:
                op1 = 32768 + butter_bandpass_filter(adc, lowcut, highcut, fs, order=o)

            class aScope(object):
                def __init__(self, ax, maxt=2*T, dt=Ts):
                    self.ax = ax
                    self.dt = dt
                    self.maxt = maxt
                    self.tdata = [0]
                    self.ydata = [0]
                    self.line = Line2D(self.tdata, self.ydata)
                    self.ax.add_line(self.line)
                    self.ax.set_ylim(-350,350)
                    self.ax.set_xlim(0, self.maxt)
            
                def aupdate(self, y):
                    lastt = self.tdata[-1]
                    if continous :
                        if lastt > self.tdata[0] + self.maxt:
                            self.ax.set_xlim(lastt-self.maxt, lastt)
            
                    t = self.tdata[-1] + self.dt
                    self.tdata.append(t)
                    self.ydata.append(y)
                    self.line.set_data(self.tdata, self.ydata)
                    return self.line,
            
            def sineEmitter():
                for i in x:
                    yield math.ceil(yout[i])

            fig = plt.Figure(figsize=(6,4))
            canvas = FigureCanvasTkAgg(fig, master=root)
            canvas.get_tk_widget().place(x=0, y=190)
            ax1 = fig.add_subplot(111)
            ax1.set_xlabel("Time")
            ax1.set_ylabel("Amplitude")
            #line, = ax1.plot(x, np.sin(x))
            scope = aScope(ax1)
            
            generateInputSignal.ani = animation.FuncAnimation(fig, scope.aupdate, sineEmitter, interval=10,blit=True)
    elif type_of_measurement == "Voltage - DC":
        lowcut = 25
        o = 3
        N = 40000
        Ts=1/fs
        if input_volt<range2:
            print("Input voltage(Amplitude) is ",input_volt)       
            print("Sampling Frequency is ",fs)
            
            continous  = True

            input_volt=int(input_volt_amplitude.get())#----------input from amplitude

            yout = (input_volt + ((0.01*input_volt*np.random.randn(N))))
            ip = (input_volt + ((0.01*input_volt*np.random.randn(N))))*5/range2
            adc=((ip/5)*65536)

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
            generateInputSignal.ani = animation.FuncAnimation(fig, animate, fargs=(x,y),interval=1)
            
            ax1 = fig.add_subplot(111)
            ax1.set_xlabel("Time")
            ax1.set_ylabel("Amplitude")
            line, = ax1.plot(x, np.sin(x))

def generateOutputSignal():
    type_of_measurement = measurement_choices.get()
    m_type.set(type_of_measurement)

    Range = choices.get()
    range_label_value1.set(Range)

    input_volt=input_volt_amplitude.get()
    InVolt_label_value1.set(input_volt)
    
    attenuation_value.set(attenuation_factor)
    
    print("Type of measurement : ",type_of_measurement)
    print("Range is : ",Range)
    iterDC = 0
    iterAC = 0
    #maxval = len(arr)#change here

    x = np.arange(maxval, step = 1)
    if (type_of_measurement == 'Voltage - DC'):
        while(iterDC < maxval ):
            opc.append((lis[iterDC]/65536)*Range)
            iterDC = iterDC+1
    elif (type_of_measurement == 'Voltage - AC'):
        while(iterAC < maxval ):
            opc.append(((lis[iterAC]-32768)/65536)*(Range)*2.5*1.26)
            iterAC = iterAC+1

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


def resetDisplay():
    InVolt_label_value1.set(0)
    range_label_value1.set(0)
    attenuation_value.set(0)


def displayWindow():
    window2 = Toplevel(root)
    window2.title("Display")
    window2.geometry("600x700")
    window2.configure(bg='#FFFFFF')

    #Label - Measurement Calculation
    iv=Label(window2,text="Input Voltage",bg='White',fg='black',font='Helvetica 8 bold')
    iv.place(x=35, y=20)

    #Measurement Calculation value
    iv_label_value = Label(window2,text="",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = InVolt_label_value1)
    iv_label_value.place(x=50, y=40)

    #Unit
    u = Label(window2,text="Unit",bg='White',fg='black',font='Helvetica 8 bold')
    u.place(x=200,y=20)
    #Unit value
    u1 = Label(window2,text="Volts",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)
    u1.place(x=200, y=40)

    #Measurement Type
    mt = Label(window2,text="Measurement Type",bg='White',fg='black',font='Helvetica 8 bold',width=15)
    mt.place(x=50, y=90)
    #Measurement Type value
    mt1 = Label(window2,text="",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = m_type)
    mt1.place(x=50, y=120)

    #Range
    r = Label(window2,text="Range",bg='White',fg='black',font='Helvetica 8 bold',width=15)
    r.place(x=200, y=90)
    #Range value
    r1 = Label(window2,text="",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = range_label_value1)
    r1.place(x=200, y=120)

    #Range
    a = Label(window2,text="Attenuation factor",bg='White',fg='black',font='Helvetica 8 bold',width=15)
    a.place(x=360, y=90)
    #Range value
    a1 = Label(window2,text="0.014",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)
    a1.place(x=355, y=120)

    #Draw button
    graph_button = Button(window2, text="Execute",bg='brown',fg='white',width=10, command=generateOutputSignal)
    graph_button.place(x=50, y=170)

    #Reset button
    reset_button = Button(window2,text="Reset", bg='brown',fg='white',width=10, command=resetDisplay)
    reset_button.place(x=400, y=170)

#Assigning values
measurement_type = {"Voltage - AC", "Voltage - DC"}

#Label - Type of Measurement
type_label=Label(root,text="Type of Measurement",bg='White',fg='black',font='Helvetica 8 bold')
type_label.place(x=50, y=10)
measurement_choices.set("Voltage - AC")

#Option Menu to select Measurement type
measur_type = OptionMenu(root,measurement_choices, *measurement_type, command=on_option_change)
measur_type.config(bg = "LightYellow2")
measur_type.configure(width=15)
measur_type.place(x=50, y=35)

range_label=Label(root,text="Range",bg='White',fg='black',font='Helvetica 8 bold')
range_label.place(x=250, y=10)
#measurement_choices.set(230)

ac_range ={110,230,440,500}
dc_range = {10,24,48}
input_range = {110,230,440,500}

selected = measurement_choices.get()
if selected ==  "Voltage - AC":
    rangeL = OptionMenu(root,choices, *ac_range)
    rangeL.config(bg = "LightYellow2")
    rangeL.configure(width=15)
    rangeL.place(x=250, y=35)
    choices.set(230)
if selected == "Voltage - DC":
    rangeL = OptionMenu(root,choices, *dc_range)
    rangeL.config(bg = "LightYellow2")
    rangeL.configure(width=15)
    rangeL.place(x=250, y=35)
    choices.set(230)

#unit
unit_range_label = Label(text="Unit",bg='White',fg='black',font='Helvetica 8 bold')
unit_range_label.place(x=465, y=10)

unit_range_label1 = Label(text="Volts",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)
unit_range_label1.place(x=430, y=40)

#Signal Frequency
signal_freq_label =Label(text="Signal Frequency",bg='White',fg='black',font='Helvetica 8 bold')
#signal_freq_label.place(x=30, y=100)
signal_freq_label.place(x=290, y=100)

signal = DoubleVar()
signal_freq_entry = Entry(root, width = 15, textvariable = signal)
#signal_freq_entry.place(x=30, y=130)
signal_freq_entry.place(x=290, y=130)

#Amplitude
amplitude_label = Label(text="Input Voltage",bg='White',fg='black',font='Helvetica 8 bold')
amplitude_label.place(x=160, y=100)

input_volt_amplitude = DoubleVar()
amplitude_entry = Entry(root, width = 15, textvariable = input_volt_amplitude)
amplitude_entry.place(x=160, y=130)

#Sampling Frequency
sampling_freq_label = Label(text="Sampling Frequency",bg='White',fg='black',font='Helvetica 8 bold')
#sampling_freq_label.place(x=290, y=100)
sampling_freq_label.place(x=430, y=100)

sam_fre = DoubleVar()
sampling_freq_entry = Label(text="12",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = sam_fre)
sampling_freq_entry.place(x=430, y=130)
sam_fre.set(1000)

#Attenuation Factor
attenuation_factor_label = Label(text="Attenuation Factor",bg='White',fg='black',font='Helvetica 8 bold',width=15)
#attenuation_factor_label.place(x=430, y=100)
attenuation_factor_label.place(x=30, y=100)

attenuation = DoubleVar()
attenuation_factor_value_label = Label(text="Attenuation Value",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = attenuation)
#attenuation_factor_value_label.place(x=430, y=130)
attenuation_factor_value_label.place(x=30, y=130)
attenuation.set(0.014)

#Draw button
graph_button = Button(root, text="Execute",bg='brown',fg='white', command=generateInputSignal)
graph_button.place(x=45, y=160)

button = Button(root, text = 'Display',bg='brown',fg='white', command= displayWindow)
button.place(x=145, y=160)

#Reset button
reset_button = Button(root,text="Reset", bg='brown',fg='white', command=reset)
reset_button.place(x=250, y=160)

root.mainloop()
