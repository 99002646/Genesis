#include <string.h>
const double CALL_RATE = 0.1;

struct Customer {
  int id;
  char name[20];
  char phone[12];
  double balance;
};
void open(struct Customer *ptr, int x, const char *nstr, const char *pstr, double y) {
  ptr->id = x;
  strcpy(ptr->name, nstr);
  strcpy(ptr->name, pstr);
  ptr->balance = y;
}
void credit(struct Customer *ptr, double amount) { ptr->balance += amount; }
void makeCall(struct Customer *ptr, int nmins) { ptr->balance -= nmins * CALL_RATE; }
double getBalance(const struct Customer *ptr) { return ptr->balance; }
void display(const struct Customer *ptr) {
  // print ptr->id,ptr->name, ptr->phone ptr->balance
}
int main() {
  struct Customer c1;
  open(&c1, 1001, "John", "9845012345", 500);
  makeCall(&c1, 10);
  credit(&c1, 100);
  display(&c1);
  // print getBalance(&a1);  //a1.balance;
  return 0;
}
