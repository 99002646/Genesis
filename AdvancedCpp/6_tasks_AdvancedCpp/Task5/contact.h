  #ifndef __CONTACT_H
  #define __CONTACT_H
  using namespace std;
  #include<string>
  class contact
  {
      std::string fname,lname,pnum,anum;
  public:
      contact();
      contact(std::string,std::string,std::string,std::string);
      contact(std::string,std::string,std::string);
      contact (const contact &ref);
      void display();
      std::string getprimaryno();
      std::string getfirstname();
      std::string getlastname();
      void setfirstname(std::string name1);
      void setlastname(std::string name2);

  };
#endif
