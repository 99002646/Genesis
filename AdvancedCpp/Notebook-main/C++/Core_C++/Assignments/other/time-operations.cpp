class MyTime {
  //TODO: data members : hours, minutes, seconds
  public:
  //TODO: Suitable default, parameterized constructors
  //TODO: Define copy constructor
  //TODO: necessary operator overloding as per the test code in main
  //TODO: display function to print time in hh:mm:ss format
};
int main() {
  MyTime t1(10,20,15);
  MyTime t2(1, 10, 5);
  MyTime t3;         // Time will be 00:00:00
  t3 = t1 + t2;      // t3 will be 11:30:20
  MyTime t4;
  t4 = t1 + 50;      // 50 seconds will be added, t4 will be 10:21:05
  ++t1;              // t1 will be 10:20:16
  (++t2).display();  // t2 will be 1:10:6, same will be displayed
  /* Optional:-
  t4 = t1;
  t1 == t2
  std::cout << t1 << "\n";
  */
   return 0;
}
