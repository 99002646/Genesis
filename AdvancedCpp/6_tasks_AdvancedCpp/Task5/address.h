#ifndef __ADDRESS_H
#define __ADDRESS_H
#include<list>
#include<iostream>
#include"contact.h"
class Address{
   std::list<contact> contacts;
public:
   void addContact(std::string,std::string,std::string,std::string);
   void displayAll();
   void removeContactBypnum(std::string); //by id
   contact* findContactBypnum(std::string);
   contact* findContactWithMatchname(std::string,std::string);//by firstname & lastname
   void updateContactdetails(std::string,std::string,std::string);
   int  countAll(){return contacts.size();}
};
#endif
