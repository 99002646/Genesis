//TODO: Implement IP Address class in suitable file hierarchy
// Data members - a, b, c, d
int main() {
  IPAddress ip1;        //Loopback 127.0.0.1
  IPAddress ip2(192, 168, 72, 25);
  IPAddress ip3("192.168.72.25");
  //ip1.isLoopback()
  ip1.display();
  ip2.display();   // "192.168.72.25"
  ip3.display();
  return 0;
}
