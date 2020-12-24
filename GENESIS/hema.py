import tkinter as tk
from tkinter import Frame, Button, Canvas
import matplotlib
matplotlib.use('TkAgg')
import numpy as np
import matplotlib.pyplot as plt
from math import pi
#from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.backends.backend_tkagg import ( FigureCanvasTkAgg, NavigationToolbar2Tk)
from matplotlib.figure import Figure
from matplotlib.lines import Line2D
import matplotlib.animation as animation
import pylab
from pylab import *

def plot ():
    F=float(signal.get())
    input_volt=float(amplitude.get())
    Fs=float(sampling.get())
    range2= float(choices.get())

    #F = 100          # No. of cycles per second, F = 500 Hz
    T = 10.e-3         # Time period, T = 2 ms
    #Fs = 1000        # No. of samples per second, Fs = 50 kHz
    Ts = 1./Fs        # Sampling interval, Ts = 20 us
    N = int(T/Ts)     # No. of samples for 2 ms, N = 100
 
    #input_volt=230    #input voltage.
                  #Vout=Asine(2*pi*f*t)
 
    t = np.linspace(0, T, N)
    amp= 1.414*input_volt
    a=[0]*(N)
    for n in range(N):
        a[n]= (amp *np.sin(2*pi*F*n/Fs))
        print(a[n])
    #signal = (amp * np.sin(2*np.pi*F*t))
 
    plt.plot(t, a)
    plt.xlabel('Time (s)')
    plt.ylabel('Voltage (V)')
    plt.grid(True)
    plt.show()


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

#Draw button
graph_button = tk.Button(root, text="Execute",bg='brown',fg='white', command=plot)
graph_button.place(x=45, y=160)


root.mainloop()
    
