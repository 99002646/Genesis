enum Color {
  RED=0xFF0000,          //(255,0,0) -> (0,255,255)    
  GREEN=0x00FF00,
  BLUE=0X0000FF, 
  WHITE,
  BLACK,
  YELLOW
  //TODO: add any other std colors
};
class Color {
  //TODO: data members - r, g, b
  public:
  //TODO: suitable constructors
  //TODO: suitable functions, e.g. display, invert  //0xFF0000, invert:- 0x00FFFF
};
int main() {
  Color c1(RED);
  Color c2(255, 0, 255);   // 0xFF, 0, 0xFF
  Color c3(0x7F007F);
  Color c4("0x7F007F");
};
