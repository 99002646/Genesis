
'''
1. Socket -> Object Handler
2. Bind -> Attach ip and port(>1024)
3. Listen -> listen for connections from the clinet
4. accept -> accept connection
5. send/receive
6. close
 
SOCK_STREAM  =  connection oriented
127.0.0.1 for loop back address of local

'''

import os
os.system("clear")

from socket import socket
from socket import AF_INET          # IP
from socket import SOCK_STREAM      #Connection oriented


def tx(line,msg):
    msg = msg + '\n'
    line.send(msg.encode())

def rx(line,ln):
    data = line.recv(ln).decode()
    return data


# Setup server
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('127.0.0.1',9999))
serverSocket.listen(10)


while True:
    print('Waiting for connections..')
    connection,addr = serverSocket.accept()
    os.system("clear")
    
    print('Client Connected :',str(addr))

    tx(connection,'welcome')
    print('c:',rx(connection,1024))

    connection.close()



 # msg = 'welcome\n'
   # clientSocket.send(msg.encode())  # send ack