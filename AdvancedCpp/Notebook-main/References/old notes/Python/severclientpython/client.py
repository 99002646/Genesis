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

serverIp = '127.0.0.1'
serverPort = 9999

clientSocket = socket(AF_INET,SOCK_STREAM)

clientSocket.connect((serverIp,serverPort))
print('Server Connected : ',serverIp,',',serverPort)

print("S:",rx(clientSocket,1024)) #get the ack
tx(clientSocket,"i am clinet")
tx(clientSocket,"Enter Mob No.")

clientSocket.close()









'''

Communication

// Server setup
Server Socket
bind
listen

//Client setup
Client Socket


//server -client communication

1. server -> accept   ---    client <- requestToconnect
2. server -> Ack(Welcome)  ---  client rx
3. 


'''