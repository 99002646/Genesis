#include "contact.h"
#include<string>
#include<iostream>
using namespace std;
contact::contact(): fname(""),lname(""),pnum(""),anum("") {}

contact::contact(std::string name1,std::string name2,std::string prnum,std::string alnum) :
    fname(name1),lname(name2),pnum(prnum),anum(alnum) {}

contact::contact(std::string name1,std::string name2,std::string prnum) :
    fname(name1),lname(name2),pnum(prnum),anum("") {}

contact::contact (const contact &ref):
    fname(ref.fname),lname(ref.lname),pnum(ref.pnum),anum(ref.anum) {}

void contact::display()
{
    std::cout<<fname<<"\n"<<lname<<"\n"<<pnum<<"\n"<<anum<<"\n";
}
std::string contact::getprimaryno()
{
    return pnum;
}
std::string contact::getfirstname()
{
    return fname;
}
std::string contact::getlastname()
{
    return lname;
}
void contact::setfirstname(std::string name1)
{
    fname=name1;
}
void contact::setlastname(std::string name2)
{
    lname=name2;
}
