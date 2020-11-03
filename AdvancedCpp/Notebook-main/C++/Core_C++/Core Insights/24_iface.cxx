#include <string>
class IEmployee {
public:
  virtual void display() = 0;
  virtual void payroll() = 0;
  virtual void appraisal() = 0;
};
class Employee : public IEmployee {
  int empid;
  std::string empname;
  double salary;
  int exp;

public:
  void display() {}
  void payroll() {}
  void appraisal() {}
};
int main() {}