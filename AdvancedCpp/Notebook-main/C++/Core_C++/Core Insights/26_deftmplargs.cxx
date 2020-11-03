template<typename T1, typename T2, typename T3=int>
void test(T1 x,T2 y, T3 z) {
  //print x, y, z
}
int main() {
    test<int,float>(10,2.3f,20);
    test(10,20,30);
    return 0;
}
