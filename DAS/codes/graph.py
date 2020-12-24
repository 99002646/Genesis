
from tkinter import *
from tkinter import messagebox

root=Tk()
root.title("Collatz  Conjecture")

import textwrap

# Matplotlib imports

import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg # NavigationToolbar2TkAgg
from matplotlib.figure import Figure 


 # Functions

lst = []

def collatz(num):
    lst.clear()
    while num != 1:
        lst.append(num)

        if num % 2 == 0:
            num = int(num / 2)

        else:
            num = int(3 * num + 1)

def main(event):
    num = int(inp_ut.get())

    collatz(num)


    output1.delete(1.0, END)
    output1.insert(END, lst)
    output2.delete(1.0, END)
    output2.insert(END, "Number of iterations: " + str(len(lst)))
    # Generate the data and populate the canvas once. 
    f = Figure(figsize = (4,3), dpi = 100)                  # Create the figure
    a = f.add_subplot(111)                                  # Add subplot
    a.plot(lst)
    canvas = FigureCanvasTkAgg(f, root)
    canvas.draw()
    canvas.get_tk_widget().grid(row = 6, column = 0)         
    canvas._tkcanvas.grid(row = 6, column = 0)


lbl1 = Label(root, width = 20, text = "Type in number\n & press Enter")
lbl1.grid(row = 1, column = 0, sticky = W)
lbl2 = Label(root, width = 40, text = "THE COLLATZ CONJECTURE")
lbl2.grid(row = 4, column = 0)

inp_ut = Entry(root, width = 20, bg = "light grey")
inp_ut.grid(row = 1, padx = 6, sticky = E)
inp_ut.get()
inp_ut.bind("<Return>", main)

# Canvas
# canvas = Canvas(root, width= 350, height= 350, bg = "white")
# canvas.grid(row = 6, column = 0, padx = (5,5), pady = (5,5))

bt1 = Button(root, width = 10, text = "About")
bt1.grid(row = 7, column = 0, pady = (5,7))

output1 = Text(root, wrap = WORD, width = 50, height = 7, bg =   "light grey")  # Note word wrap attribute
output1.grid(row = 3, column = 0, padx = (5,1), sticky = W)
output2 = Text(root, width = 50, height = 1, bg = "white")
output2.grid(row = 2, column = 0, sticky = W)


def about():

    messagebox.showinfo("About", "The Collatz conjecture states that if you pick any positive whole number, and if its even, you divide it by two and if its odd, you multiply it by three and add one, and if you repeat this procedure often enough, the number that you started with will eventually reduce to one and if you play this game for long enough, your friends will eventually stop calling to see if you want to hang out ")

btn1 = Button(root, text = "About", command = about)
btn1.grid(row = 7, column = 0, pady = (5,7))


root.mainloop()