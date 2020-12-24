import tkinter as tk
from tkinter import Frame, Button, Canvas
import matplotlib
matplotlib.use('TkAgg')
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib.figure import Figure
from matplotlib.lines import Line2D
import numpy as np
from math import pi
import math
import pickle
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
temp=[]
List_type=[]
list_dc=[]
type_of_measurement = ""
range2=0
list1=[]
input_volt=0
#attenuation_factor=0.014
fs=1000

def convert_into_eight_bits(value):
    MSB = (value >> 8) & 0xff
    LSB = value & 0xff
    return MSB,LSB

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

def plot ():
    input_volt=int(input_volt_amplitude.get())#----------input from amplitude
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
            amp = 1.414*input_volt      

            T = 1/f
            Ts = 1/fs
            harmonic_amp1=0.05*amp
            harmonic_amp2=0.05*amp
            #attenuation_factor=(amp+harmonic_amp1+harmonic_amp2)/2.5
            attenuation_factor= (range2 + 0.5*range2) /2.5
            #attenuation_factor_value_label['text'] = attenuation_factor
            numberlist.append(str(attenuation_factor))
            attenuation.set(attenuation_factor)
            continous  = True

            fig = plt.Figure()
            x = np.arange(fs)
            yout= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs)))) for i in x ]
            yo= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs))))*(1/attenuation_factor) for i in x ]
                    
            adc=[((yo[i]/5)*65536)+(32768) for i in x]
            for i in x:
                op1 = 32768 + butter_bandpass_filter(adc, lowcut, highcut, fs, order=o)
                List_type = op1.tolist()
            for i in List_type:
                numberlist.append(convert_into_eight_bits(math.ceil(i)))

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
   
            # pass a generator in "sineEmitter" to produce data for the update func
            plot.ani = animation.FuncAnimation(fig, scope.aupdate, sineEmitter, interval=10,blit=True)
        else:
            print("Signal Frequency is ",f)
            print("Input Voltage(Amplitude) is ",input_volt)       
            print("Sampling Frequency is ",fs)
            #attenuation.set(attenuation_factor)

            #Parameters
            amp = 1.414*input_volt       #(Amplitude)
            T = 1/f
            Ts = 1/fs
            harmonic_amp1=0.05*amp
            harmonic_amp2=0.05*amp
            #attenuation_factor=(amp+harmonic_amp1+harmonic_amp2)/2.5
            attenuation_factor= (range2 + 0.5*range2) /2.5
            numberlist.append(str(attenuation_factor))
            attenuation.set(attenuation_factor)
            
            continous  = True

            fig = plt.Figure()
            x = np.arange(fs)
           
            yout= [ 0 for i in x ]
            yo= [ 0 for i in x ]
                    
            adc=[((yo[i]/5)*65536)+(32768) for i in x]
            for i in x:
                op1 = 32768 + butter_bandpass_filter(adc, lowcut, highcut, fs, order=o)
                List_type = op1.tolist()
                      
            for i in List_type:
                numberlist.append(convert_into_eight_bits(math.ceil(i)))
        
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
            
            plot.ani = animation.FuncAnimation(fig, scope.aupdate, sineEmitter, interval=10,blit=True)
            
    elif type_of_measurement == "Voltage - DC":
        lowcut = 25
        o = 3
        N = 100
        Ts=1/fs
        if input_volt<range2:
            print("Input voltage(Amplitude) is ",input_volt)       
            print("Sampling Frequency is ",fs)
            
            input_volt=int(input_volt_amplitude.get())#----------input from amplitude
            #ip = 100 + ((3*np.random.randn(N)))
            attenuation_factor = range2/5
            attenuation.set(attenuation_factor)
            yout = (input_volt + ((0.01*input_volt*np.random.randn(N))))
            ip = (input_volt + ((0.01*input_volt*np.random.randn(N))))*5/range2
            adc=((ip/5)*65536)
            x = []
            #N = fs
            N2=N/10
            y = []
            it=0
            i=0
            while(it < N):
                op = butter_lowpass_filter(adc,lowcut,fs,order = o)
                op1 = gaussian_filter1d(op, 12)
                it = it + 1
            List_type = op1.tolist()
            #print(type(List_type))
            for i in List_type:
                numberlist.append((math.ceil(i)))
            '''
            def animate(i,x,y):
                x.append(i)
                y.append(input_volt + ((0.01*input_volt*random.randint(-5,5))))
                i+=1
                x=x[:100]
                y=y[:100]
                if(i < 100):
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
            '''
        else:
            #error messege
            tk.messagebox.showerror("Error", "Exceeds the range")
            tk.messagebox.showinfo("Hint","The Amplitude value is always lesser than range value.")
    return numberlist
def reset():
    signal.set(50)
    input_volt_amplitude.set(220)
    #sampling.set(0)
    sam_fre.set(1000)
    measurement_choices.set("Voltage - AC")
    choices.set(230)
    #attenuation.set(0.014)
    signal_freq_entry['state'] = 'normal'

def on_option_change(event):
    selected = measurement_choices.get()
    if selected == "Voltage - AC":
        #input_range = {110,230,440,500}
        rangeL = tk.OptionMenu(root,choices, *ac_range)
        rangeL.config(bg = "LightYellow2")
        rangeL.configure(width=15)
        rangeL.place(x=250, y=35)
        choices.set(230)
        signal_freq_entry['state'] = 'normal'

    elif selected == "Voltage - DC":
        #input_range = {10,24,48}
        rangeL = tk.OptionMenu(root,choices, *dc_range)
        rangeL.config(bg = "LightYellow2")
        rangeL.configure(width=15)
        rangeL.place(x=250, y=35)
        choices.set(10)
        signal_freq_entry['state'] = 'disabled'

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

ac_range ={110,230,440,500}
dc_range = {10,24,48}
#input_range = {110,230,440,500}

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

#Unit
unit_range_label = tk.Label(text="Unit",bg='White',fg='black',font='Helvetica 8 bold')
unit_range_label.place(x=465, y=10)

unit_range_label1 = tk.Label(text="Volts",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)
unit_range_label1.place(x=430, y=40)

#Signal Frequency
signal_freq_label = tk.Label(text="Signal Frequency",bg='White',fg='black',font='Helvetica 8 bold')
signal_freq_label.place(x=290, y=100)

signal = tk.DoubleVar()
signal_freq_entry = tk.Entry(root, width = 15, textvariable = signal)
signal_freq_entry.place(x=290, y=130)

#Amplitude
amplitude_label = tk.Label(text="Input Voltage",bg='White',fg='black',font='Helvetica 8 bold')
amplitude_label.place(x=160, y=100)

input_volt_amplitude = tk.DoubleVar()
amplitude_entry = tk.Entry(root, width = 15, textvariable = input_volt_amplitude)
amplitude_entry.place(x=160, y=130)

#Sampling Frequency
sampling_freq_label = tk.Label(text="Sampling Frequency",bg='White',fg='black',font='Helvetica 8 bold')
sampling_freq_label.place(x=430, y=100)

sam_fre = tk.DoubleVar()
sampling_freq_entry = tk.Label(text="12",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = sam_fre)
sampling_freq_entry.place(x=430, y=130)
sam_fre.set(1000)

#Attenuation Factor
attenuation_factor_label = tk.Label(text="Attenuation Factor",bg='White',fg='black',font='Helvetica 8 bold',width=15)
attenuation_factor_label.place(x=30, y=100)

attenuation = tk.DoubleVar()
attenuation_factor_value_label = tk.Label(text="Attenuation Value",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = attenuation)
attenuation_factor_value_label.place(x=30, y=130)
#attenuation.set(0.014)

#Draw button
graph_button = tk.Button(root, text="Execute",bg='brown',fg='white', command=plot)
graph_button.place(x=45, y=160)

#Reset button
reset_button = tk.Button(root,text="Reset", bg='brown',fg='white', command=reset)
reset_button.place(x=250, y=160)
k=0
root.mainloop()
print(numberlist)
HOST = '127.0.0.1'
PORT = 5032
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr) 
        while True:
            for i in numberlist :
                k=k+1
                for j in i :
                    if not i:
                        break
                    data=str(numberlist)
                    data=data.encode()
                    conn.sendall(data)
                    if k == 100:
                        time.sleep(0.1)
                        k=0
conn.close()
