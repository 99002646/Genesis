import tkinter as tk
from tkinter import Frame, Button, Canvas
import matplotlib
matplotlib.use('TkAgg')
import numpy as np
import matplotlib.pyplot as plt
from math import pi
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
#from matplotlib.backends.backend_tkagg import ( FigureCanvasTkAgg, NavigationToolbar2Tk)
from matplotlib.figure import Figure
from matplotlib.lines import Line2D
import matplotlib.animation as animation
import pylab
#from pylab import *
fig = plt.Figure()
def plot ():
    #f=int(signal.get())
    #input_volt=int(amplitude.get())#----------input from amplitude
    #fs=int(sampling.get()) 
    #range2=440 
    input_volt=230#-------------input from amplitude
    type_of_measurement = measurement_choices.get()
    range2 = choices.get()
    print("Type of measurement : ",type_of_measurement)
    print("Range is : ",range2)
    
    if type_of_measurement == "Voltage - AC":

        if input_volt<range2:
            #print("Signal Frequency is ",f)
            #print("Amplitude is ",input_volt)       
            #print("Sampling Frequency is ",fs)
            #print("Range is ",range2)
            
            #Parameters
            #input_volt=230#-------------input from amplitude
            amp = 1.414*input_volt       #          (Amplitude)
            f = 50        #      (Frequency)---------------signal frequency
            fs = 5000    #     (Sample Rate)-----------------sampling freq
            T = 1/f
            Ts = 1/fs
            harmonic_amp1=0.05*amp
            harmonic_amp2=0.05*amp
            attenuation_factor=(amp+harmonic_amp1+harmonic_amp2)/2.5
            #attenuation_factor_value_label['text'] = attenuation_factor
            attenuation.set(attenuation_factor)
            continous  = True

            #f = Figure(figsize=(6,4), dpi=100)
            fig = plt.Figure()
            x = np.arange(fs)
            #print(x)
            y= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs))))*(1/attenuation_factor) for i in x ]
            for i in x:
                #print((y[i]))
                adc=int((y[i]/5)*65536)+(32768)
                #print(adc)
            #adc=((y/10)*65536)+(32768)
            class Scope(object):
                def __init__(self, ax, maxt=2*T, dt=Ts):
                    self.ax = ax
                    self.dt = dt
                    self.maxt = maxt
                    self.tdata = [0]
                    self.ydata = [0]
                    self.line = Line2D(self.tdata, self.ydata)
                    self.ax.add_line(self.line)
                    self.ax.set_ylim(-2.5, 2.5)
                    self.ax.set_xlim(0, self.maxt)
            
                def update(self, y):
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
                    yield y[i]
            #fig, ax = plt.subplots()
            #f = Figure(figsize=(6,4), dpi=100)
            fig = plt.Figure(figsize=(6,4))
            canvas = FigureCanvasTkAgg(fig, master=root)
            canvas.get_tk_widget().place(x=0, y=190)
            ax1 = fig.add_subplot(111)
            ax1.set_xlabel("Time")
            ax1.set_ylabel("Amplitude")
            line, = ax1.plot(x, np.sin(x))
            scope = Scope(ax1)
            
            # pass a generator in "sineEmitter" to produce data for the update func
            plot.ani = animation.FuncAnimation(fig, scope.update, sineEmitter, interval=10,blit=True)
        else:
            #error messege
            tk.messagebox.showerror("Error", "Exceeds the range")
            tk.messagebox.showinfo("Hint","The Amplitude value is always lesser than range value.")

    elif type_of_measurement == "Voltage - DC":
        print("hellooooo")

def reset():
    signal.set(0)
    amplitude.set(0)
    sampling.set(0)
    measurement_choices.set("Voltage - AC")
    choices.set(0)
    attenuation.set(0)
    #canvas.delete('all')
    #animation.destroy()

def on_option_change(event):
    selected = measurement_choices.get()
    if selected == "Voltage - AC":
        input_range = {110,230,440,500}
        
    elif selected == "Voltage - DC":
        input_range = {10,50,48}

    input_range=sorted(input_range)    
    range_label= tk.Label(root,text="",bg='White',fg='black',font='Helvetica 8 bold')
    range_option = tk.OptionMenu(root,choices, *input_range)
    choices.set(0)
    range_option.config(bg = "LightYellow2")
    range_option.configure(width=15)

    if selected == "Voltage - AC":
        signal.set(0)
        amplitude.set(0)
        sampling.set(0)
        range_label['text'] = "Range"
        range_label.place(x=300, y=10)
        #choices.set(0)
        range_option.configure(width=15)
        range_option.place(x=260, y=35)

    elif selected == "Voltage - DC":
        signal.set(0)
        amplitude.set(0)
        sampling.set(0)
        range_label['text'] = "Range"
        range_label.place(x=300, y=10)
        #choices.set(0)
        range_option.configure(width=15)
        range_option.place(x=260, y=35)

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

#Signal Frequency
signal_freq_label = tk.Label(text="Signal Frequency",bg='White',fg='black',font='Helvetica 8 bold')
signal_freq_label.place(x=30, y=100)

signal = tk.DoubleVar()
signal_freq_entry = tk.Entry(root, width = 15, textvariable = signal)
signal_freq_entry.place(x=30, y=130)

#Amplitude
amplitude_label = tk.Label(text="Input Voltage",bg='White',fg='black',font='Helvetica 8 bold')
amplitude_label.place(x=160, y=100)

amplitude = tk.DoubleVar()
amplitude_entry = tk.Entry(root, width = 15, textvariable = amplitude)
amplitude_entry.place(x=160, y=130)

#Sampling Frequency
sampling_freq_label = tk.Label(text="Sampling Frequency",bg='White',fg='black',font='Helvetica 8 bold')
sampling_freq_label.place(x=290, y=100)

sampling = tk.DoubleVar()
sampling_freq_entry = tk.Entry(root, width = 15, textvariable = sampling)
sampling_freq_entry.place(x=290, y=130)

#Attenuation Factor
attenuation_factor_label = tk.Label(text="Attenuation Factor",bg='White',fg='black',font='Helvetica 8 bold',width=15)
attenuation_factor_label.place(x=430, y=100)

attenuation = tk.DoubleVar()
attenuation_factor_value_label = tk.Label(text="Attenuation Value",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = attenuation)
attenuation_factor_value_label.place(x=430, y=130)

#Draw button
graph_button = tk.Button(root, text="Execute",bg='brown',fg='white', command=plot)
graph_button.place(x=45, y=160)

#Reset button
reset_button = tk.Button(root,text="Reset", bg='brown',fg='white', command=reset)
reset_button.place(x=250, y=160)

root.mainloop()