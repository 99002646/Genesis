from socket import *;

'''
socket
connect
send or recv
close
'''

client_socket=socket(AF_INET,SOCK_STREAM);
client_socket.connect(("127.0.0.1",9999));
data="I am client.....helloo";
client_socket.send(data.encode());
#print("client details",client_socket);
data=client_socket.recv(1024);
print("masg from server:",data.decode());
client_socket.close();