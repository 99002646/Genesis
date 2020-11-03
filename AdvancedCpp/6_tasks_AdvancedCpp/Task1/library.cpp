#include<iostream>
#include<list>
#include<iterator>
#include<string>
#include<algorithm>
#include"book.h"
#include"library.h"

void Library::addBook(int id,std::string title1,std::string title2,std::string title3,double cost, int pag){
	lib.push_back(Book(id,title1,title2,title3,cost,pag));
}
void Library::removeBook(int id){
	auto iter = std::find_if(lib.begin(),lib.end(),[=]( Book& l1){ return (l1.getId()==id);});
	
	lib.erase(iter);	
}
Book* Library::findbook(int id){
    
    std::list<Book>::iterator iter;
    for(iter=lib.begin();iter!=lib.end();++iter)
    {
        if(iter->getId()==id)
        {
            return &(*iter);
        }
    }
    return NULL;	
}
Book* Library::findbook(std::string author_name){
    std::list<Book>::iterator iter;
    for(iter=lib.begin();iter!=lib.end();++iter)
    {
        if(iter->getauthor()==author)
        {
            return &(*iter);
        }
    }
    return NULL;
}
double Library::averagePrice(){
	std::list<Book>::iterator iter;
  	double total=0;
  	int count=0;
  	for(iter=lib.begin();iter!=lib.end();++iter)
    {
        total=total+iter->getprice();
      	count=count+1;
    }
  	double average;
  	average=(total/count);
  	return average;
}
int Library::maxpages(){
    std::list<Book>::iterator iter=lib.begin();
  	auto Maxpage=iter;
  	int Max=iter->getpages();
    for(;iter!=lib.end();++iter)
    {
        if(iter->getpages()>Max)
        {
            Maxpage=iter;
          	Max=iter->getpages();
        }
    }
    return Max;
}
int Library::minpages(){
    std::list<Book>::iterator iter=lib.begin();
  	auto Minpage=iter;
  	int Min=iter->getpages();
    for(;iter!=lib.end();++iter)
    {
        if(iter->getpages()<Min)
        {
            Minpage=iter;
          	Min=iter->getpages();
        }
    }
    return Min;
}
double Library::average(std::string publisher_name){
	std::list<Book>::iterator iter;
  	double total=0;
  	int count=0;
  	for(iter=lib.begin();iter!=lib.end();++iter)
    {
        if(iter->getpublisher()==publisher_name){
        	total=total+iter->getprice();
      		count=count+1;
        } 	
    }
  	double average;
  	average=(total/count);
  	return average;
}
int Library::booksrange(double rangemin, double rangemax){
	int total = std::count_if(lib.begin(),lib.end(),[=] (Book& l1)
	{ return (l1.getprice()>rangemin && l1.getprice()<rangemax); }
	);
	return total;
}
int Library::countbooks(double cost){
	int total = std::count_if(lib.begin(),lib.end(),[=] (Book& l1)
	{ return (cost<l1.getprice()); }
	);
	return total;
}
int Library::countAll(){
	lib.size();
}

 
