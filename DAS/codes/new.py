from tkinter import *
values = ["one","two","three"]
root = Tk()
var = StringVar()
var.set(values[0])
# set initial options
o = OptionMenu(root,var,*values)
o.pack()
# change options
m = o.children['menu']
m.delete(0,END)
newvalues = "a b c d e f".split()
for val in newvalues:
    m.add_command(label=val,command=lambda v=var,l=val:v.set(l))
var.set(newvalues[0])
root.mainloop()
