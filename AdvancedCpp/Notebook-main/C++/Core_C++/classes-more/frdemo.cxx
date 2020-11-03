class Sample {
  int x;
  int y;

public:
  Sample(int p, int q) : x(p), y(q) {}
  friend void setxy(Sample *, int, int);
  friend void display();
};
void setxy(Sample *ptr, int p, int q) {
  ptr->x = p;
  ptr->y = q;
}
void display(Sample &ref) {
  // print ref.x, ref.y
}
int main() {
  Sample s1(10, 20);
  setxy(&s1, 10, 20);
  display(s1);
  return 0;
}
