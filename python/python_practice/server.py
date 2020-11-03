from socket import *;

server_socket=socket(AF_INET,SOCK_STREAM);
server_socket.bind(("127.0.0.1",9999));
server_socket.listen(10);
print("waiting for clients");
connection,addr=server_socket.accept();#blocking call
data=connection.recv(1024);
#print("connection:",connection);
#print("client connected");
data=data.decode().upper();
connection.send(data.encode());
server_socket.close();