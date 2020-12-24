import tkinter as tk
#import textwrap
import matplotlib
matplotlib.use('TkAgg')
import numpy as np
import matplotlib.pyplot as plt
from math import pi
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure

def plot ():
    
    x=np.array ([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    v= np.array ([2, 3, 4, 5, 6, 7, 8, 9, 10,1])
    p= np.array ([1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2])
    '''

    F = 1.e2          # No. of cycles per second, F = 500 Hz
    T = 10.e-3         # Time period, T = 2 ms
    Fs = 1.e3        # No. of samples per second, Fs = 50 kHz
    Ts = 1./Fs        # Sampling interval, Ts = 20 us
    N = int(T/Ts)     # No. of samples for 2 ms, N = 100
 
    input_volt=230    #input voltage.
                  #Vout=Asine(2*pi*f*t)
 
    t = np.linspace(0, T, N)
    amp= 1.414*input_volt
    a=[0]*(N)
    for n in range(N):
        a[n]= (amp *np.sin(2*pi*F*n/Fs))
        print(a[n])
    #signal = (amp * np.sin(2*np.pi*F*t))
    '''
    fig = Figure(figsize=(4,4))
    a = fig.add_subplot(111)

    a.plot(p, range(2 +max(x)),color='blue')
    #a.plot(t,a,color='blue')
    a.invert_yaxis()

    a.set_title ("Estimation Grid", fontsize=16)
    a.set_ylabel("Y", fontsize=14)
    a.set_xlabel("X", fontsize=14)

    canvas = FigureCanvasTkAgg(fig, master=root)
    canvas.get_tk_widget().place(x=50, y=200)
    canvas.draw()
    '''
    F = 1.e2          # No. of cycles per second, F = 500 Hz
    T = 10.e-3         # Time period, T = 2 ms
    Fs = 1.e3        # No. of samples per second, Fs = 50 kHz
    Ts = 1./Fs        # Sampling interval, Ts = 20 us
    N = int(T/Ts)     # No. of samples for 2 ms, N = 100
 
    input_volt=230    #input voltage.
                  #Vout=Asine(2*pi*f*t)
 
    t = np.linspace(0, T, N)
    amp= 1.414*input_volt
    a=[0]*(N)
    for n in range(N):
        a[n]= (amp *np.sin(2*pi*F*n/Fs))
        print(a[n])
    #signal = (amp * np.sin(2*np.pi*F*t))
    
 
'''
'''
    plt.plot(t, a)
    plt.title ("Input Signal", fontsize=16)
    plt.xlabel('Time (s)')
    plt.ylabel('Voltage (V)')
    plt.grid(True)
    plt.show()
'''
'''
    fig = Figure(figsize=(4,4))
    a = fig.add_subplot(111)
    a.set_title ("Estimation Grid", fontsize=16)


    canvas = FigureCanvasTkAgg(fig, master=root)
    canvas.get_tk_widget().place(x=50, y=200)
    canvas.draw()
'''
def select():
    option = measurement_choices.get()
    if option=="Voltage - AC":
        dc_range.place_forget()
        ac_range.place(x=230, y=35)
    else:
        ac_range.place_forget()
        dc_range.place(x=230, y=35)

def take_input():
    option = measurement_choices.get()
    if option=="Voltage - AC":
        ac_data=ac_choices.get()
        print(option)
        print(ac_data)
    else:
        dc_data=dc_choices.get()
        print(option)
        print(dc_data)

root = tk.Tk()
root.title("Configurator")
root.geometry("500x650")

measurement_choices = tk.StringVar()
ac_choices = tk.IntVar()
dc_choices = tk.IntVar()

measurement_type = {"Voltage - AC", "Voltage - DC",}
AC_range = {110,230,440,500}
DC_range = {10,50,48}

measurement_choices.set("Measurement Type")
ac_choices.set("Select AC range")
dc_choices.set("Select DC range")

label=tk.Label(root,text="Select the Type and range")
label.place(x=130, y=10)

measur_type = tk.OptionMenu(root,measurement_choices, *measurement_type)
measur_type.configure(width=15)
measur_type.place(x=50, y=35)

AC_range=sorted(AC_range)
ac_range = tk.OptionMenu(root,ac_choices, *AC_range)
#ac_range.visible = False
ac_range.configure(width=15)
#ac_range.place(x=230, y=35)
#ac_range.pi = ac_range.place_info()

DC_range=sorted(DC_range)
dc_range = tk.OptionMenu(root,dc_choices, *DC_range)
#ac_range.visible = False
#dc_range.place(x=230, y=75)
dc_range.configure(width=15)
#dc_range.pi = dc_range.place_info()

signal_freq_label = tk.Label(text="Signal Frequency")
signal_freq_label.place(x=30, y=100)

amplitude_label = tk.Label(text="Amplitude")
amplitude_label.place(x=160, y=100)

sampling_freq_label = tk.Label(text="Sampling Frequency")
sampling_freq_label.place(x=260, y=100)


next_button = tk.Button(root,text="Next", bg="gray", command=select)
next_button.place(x=80, y=150)

print_button = tk.Button(root,text="Print", bg="gray", command=take_input)
print_button.place(x=170, y=150)

graph_button = tk.Button(root, text="draw", command=plot)
graph_button.place(x=240, y=150)

c = tk.Canvas(width=400, height=300, bg='white')
c.place(x=10, y=200)

root.mainloop()