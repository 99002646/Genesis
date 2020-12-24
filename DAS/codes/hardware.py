'''# first of all import the socket library  
import socket             
  
# next create a socket object  
s = socket.socket()       
print ("Socket successfully created") 
  
# reserve a port on your computer in our  
# case it is 12345 but it can be anything  
port = 12345                
  
# Next bind to the port  
# we have not typed any ip in the ip field  
# instead we have inputted an empty string  
# this makes the server listen to requests  
# coming from other computers on the network  
s.bind(('', port))        
print ("socket binded to %s" %(port))  
  
# put the socket into listening mode  
s.listen(5)   
print ("socket is listening")            
  
# a forever loop until we interrupt it or  
# an error occurs  
while True:  
  
# Establish connection with client.  
	c, addr = s.accept()      
	print ('Got connection from', addr ) 
  
# send a thank you message to the client.  
	str1="Thank you for connecting"
	str1=str1.encode()
	c.send(str1)  
  
# Close the connection with the client  
c.close()
'''
import PySimpleGUI as sg

# Very basic form.  Return values as a list
form = sg.FlexForm('Simple data entry form')  # begin with a blank form

layout = [
          [sg.Text('Please enter your Name, Address, Phone')],
          [sg.Text('Name', size=(15, 1)), sg.InputText('name')],
          [sg.Text('Address', size=(15, 1)), sg.InputText('address')],
          [sg.Text('Phone', size=(15, 1)), sg.InputText('phone')],
          [sg.Submit(), sg.Cancel()]
         ]

#button, values = form.LayoutAndRead(layout)

button, values = form.Layout(layout).Read()

#button, values = form(title, layout).Read()

print(button, values[0], values[1], values[2])