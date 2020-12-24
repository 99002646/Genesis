import tkinter as tk

def select():
    option = measurement_choices.get()
    if option=="Voltage - AC":
        dc_range.place_forget()
        ac_range.place(x=230, y=35)
    else:
        ac_range.place_forget()
        dc_range.place(x=230, y=35)

root = tk.Tk()

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

#def reset():



root.title("Configurator")
root.geometry("400x200")

measurement_choices = tk.StringVar()
ac_choices = tk.IntVar()
dc_choices = tk.IntVar()

measurement_type = {"Voltage - AC", "Voltage - DC",}
AC_range = {1, 50, 100, 200,300,400,500}
DC_range = {1, 6, 12, 18,24,30,36,42,48}

measurement_choices.set("Measurement Type")
ac_choices.set("AC range")
dc_choices.set("DC range")

label=tk.Label(root,text="Select the Type and range")
label.place(x=130, y=10)

measur_type = tk.OptionMenu(root,measurement_choices, *measurement_type)
measur_type.configure(width=15)
measur_type.place(x=50, y=35)

AC_range=sorted(AC_range)
ac_range = tk.OptionMenu(root,ac_choices, *AC_range)
#ac_range.visible = False
ac_range.configure(width=10)
#ac_range.place(x=230, y=35)
#ac_range.pi = ac_range.place_info()

DC_range=sorted(DC_range)
dc_range = tk.OptionMenu(root,dc_choices, *DC_range)
#ac_range.visible = False
#dc_range.place(x=230, y=75)
dc_range.configure(width=10)
#dc_range.pi = dc_range.place_info()

next_button = tk.Button(root,text="Next", bg="gray", command=select)
next_button.place(x=80, y=150)

print_button = tk.Button(root,text="Print", bg="gray", command=take_input)
print_button.place(x=170, y=150)

#reset_button = tk.Button(root,text="Reset", bg="gray", command=reset)
#reset_button.place(x=250, y=150)

root.mainloop()