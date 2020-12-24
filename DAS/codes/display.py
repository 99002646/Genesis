
import tkinter as tk
from tkinter import Frame, Button, Canvas

def plot():
    pass

def reset():
    mCalc_label_value1.set(0)
    u1['text']=" "
    mt1['text']=" "
    range_label_value1.set(0)

def exitWindow():
    root.destroy()

#Execution starts here
root = tk.Tk()
root.title("Display")
title_bar = Frame(root, bg='brown', relief='raised', bd=2)
title_bar.pack()
root.geometry("600x700")
root.configure(bg='#FFFFFF')

#Variable data types
mCalc_label_value1 = tk.DoubleVar()
unit_label_value1 = tk.StringVar()
mtype_label_value1 = tk.StringVar()
range_label_value1 = tk.DoubleVar()

#Label - Type of Measurement
mc=tk.Label(root,text="Measurement Calculation",bg='White',fg='black',font='Helvetica 8 bold')
mc.place(x=35, y=30)

#Signal Frequency
mCalc_label_value = tk.Label(text="00000",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)#, textvariable = mCalc_label_value1)
mCalc_label_value.place(x=50, y=50)

#Sampling Frequency
u = tk.Label(text="Unit",bg='White',fg='black',font='Helvetica 8 bold')
u.place(x=395,y=30)

#Amplitude
u1 = tk.Label(text="Volts",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)#, textvariable = unit_label_value1)
u1.place(x=360, y=50)

#Attenuation Factor
mt = tk.Label(text="Measurement Type",bg='White',fg='black',font='Helvetica 8 bold',width=15)
mt.place(x=50, y=100)

mt1 = tk.Label(text="AC",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15)#, textvariable = mtype_label_value1)
mt1.place(x=50, y=130)

r = tk.Label(text="Range",bg='White',fg='black',font='Helvetica 8 bold',width=15)
r.place(x=360, y=100)

r1 = tk.Label(text="r000",bg='DarkSeaGreen3',fg='black',font='Helvetica 8 bold',width=15, textvariable = range_label_value1)
r1.place(x=355, y=130)

#Draw button
graph_button = tk.Button(root, text="Show",bg='brown',fg='white',width=10, command=plot)
graph_button.place(x=50, y=200)

#Reset button
reset_button = tk.Button(root,text="Reset", bg='brown',fg='white',width=10, command=reset)
reset_button.place(x=225, y=200)

#Reset button
exit_button = tk.Button(root,text="Exit", bg='brown',fg='white',width=10, command=exitWindow)
exit_button.place(x=400, y=200)

root.mainloop()