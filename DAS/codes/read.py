import tkinter as tk 
root=tk.Tk() 
root.geometry("200x200")

a=1234
def submit(): 
    a_entry['text']= a

a_entry = tk.Label(root,text="data will be print here")
a_entry.grid(row=0,column=0)
sub_btn=tk.Button(root,text = 'Submit',command = submit)
sub_btn.grid(row=4,column=0) 

root.mainloop() 
