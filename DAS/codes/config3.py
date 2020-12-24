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

def plot ():
    
    F=float(signal.get())
    input_volt=float(amplitude.get())#----------input from amplitude
    Fs=float(sampling.get())
    range2= float(choices.get())
    
    type_of_measurement = measurement_choices.get()
    range1 = choices.get()
    print(type_of_measurement)
    print(range1)

    if input_volt<range2:
        #F = 1.e2         # No. of cycles per second, F = 500 Hz
        T = 0.3      # Time period, T = 2 ms
        #Fs = 1.e3        # No. of samples per second, Fs = 50 kHz
        Ts = 1./Fs       # Sampling interval, Ts = 20 us
        N = int(T/Ts)    # No. of samples for 2 ms, N = 100
 
        #input_volt=230   #input voltage.   #Vout=Asine(2*pi*f*t)
        print("Signal Frequency is ",F)
        print("Sampling Frequency is ",Fs)
        print("Amplitude is ",input_volt)
        print("Range is ",range2)

        t = np.linspace(0, T, N)
        amp= 1.414*input_volt
        a=[0]*(N)
        for n in range(N):
            a[n]= (amp *np.sin(2*pi*F*n/Fs))
            print(a[n])
        #signal = (amp * np.sin(2*np.pi*F*t))
        #fig = Figure(figsize=(5,5))
        #a1 = fig.add_subplot(111)
        a1.plot(t,a,color='blue')

        a1.set_title ("Sine Wave", fontsize=16)
        a1.set_ylabel("Voltage", fontsize=14)
        a1.set_xlabel("Time", fontsize=14)

        #canvas = FigureCanvasTkAgg(fig, master=root)
        canvas.get_tk_widget().place(x=30, y=200)
        #canvas.grid(True)
        canvas.draw()
    else:
        tk.messagebox.showerror("Error", "Exceeds the range")
        tk.messagebox.showinfo("Hint","The Amplitude value is always lesser than range value.")

def reset():
    signal.set(0)
    amplitude.set(0)
    sampling.set(0)
    measurement_choices.set("Voltage - AC")
    choices.set(0)
    #canvas.delete()
    #range_label.place_forget()
    #range_option.place_forget()

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
    #print(choices)

    if selected == "Voltage - AC":
        signal.set(0)
        amplitude.set(0)
        sampling.set(0)
        range_label['text'] = "AC Range"
        range_label.place(x=300, y=10)
        #choices.set(0)
        range_option.configure(width=15)
        range_option.place(x=230, y=35)

    elif selected == "Voltage - DC":
        signal.set(0)
        amplitude.set(0)
        sampling.set(0)
        range_label['text'] = "DC Range"
        range_label.place(x=300, y=10)
        #choices.set(0)
        range_option.configure(width=15)
        range_option.place(x=230, y=35)

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
amplitude_label = tk.Label(text="Amplitude",bg='White',fg='black',font='Helvetica 8 bold')
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
attenuation_factor_label = tk.Label(text="Attenuation Factor",bg='White',fg='black',font='Helvetica 8 bold')
attenuation_factor_label.place(x=430, y=100)

attenuation_factor_value_label = tk.Label(text="Attenuation Value",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold')
attenuation_factor_value_label.place(x=430, y=130)

#Print button
#print_button = tk.Button(root,text="Print", bg='brown',fg='white', command=take_input)
#print_button.place(x=45, y=160)

#Draw button
graph_button = tk.Button(root, text="Execute",bg='brown',fg='white', command=plot)
graph_button.place(x=45, y=160)

#Reset button
reset_button = tk.Button(root,text="Reset", bg='brown',fg='white', command=reset)
reset_button.place(x=250, y=160)

#Next button
#next_button = tk.Button(root,text="Next", bg='brown',fg='white', command=next)
#next_button.place(x=450, y=160)

fig = Figure(figsize=(5,5))
a1 = fig.add_subplot(111)
#a1.plot(t,a,color='blue')
canvas = FigureCanvasTkAgg(fig, master=root)

root.mainloop()