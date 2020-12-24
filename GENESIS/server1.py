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