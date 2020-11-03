#ifndef __LIBRARY_H
#define __LIBRARY_H

class Library {
  std::list<Book> books;
  public:
  void addBook(int id, std::string title, std::title author, 
                std::string publisher,double price,int pages);
  void addBook(const Book& ref);
  Book* findBookById(int id);
  void displayAll();
  void removeById(int id);
  double findAveragePrice();
  Book& findBookWithMaxPages();  //Book*
  Book& findBookWithMinPriceByPublisher(std::string); //Book*
  double findAveragePriceByPublisher(std::string);
  int countByPriceRange(int,int);
  int countByPriceLimitAndAuthor(std::string, int price);
  std::list<Book>  findAllBooksByAuthor(std::string);
  void sortByTitle();
};

void Library::addBook(int id, std::string title, std::title author, 
  std::string publisher,double price,int pages) {
  //Book temp(id,title, author, publisher, price,pages);
  //books.push_back(temp);         //Method-1, not recommended                
  books.push_back(Book(id,title,author,publisher, price,pages)); //Method-2
  //books.emplace_back(id,title,author,publisher, price,pages);
                                    //Method-3, allowed from C++11
}
void Library::addBook(const Book& ref) {
  books.push_back(ref);
}
void displayAll() {
  std::list<Book>::iterator iter;
  for(iter=books.begin();iter!=books.end();++iter)
    iter->display();    //iter->getPrice, iter->getTitle
}
Book* findBookById(int id) {
  std::list<Book>::iterator iter;
  for(iter=books.begin();iter!=books.end();++iter)
    if(iter->getId()==id)
        return &(*iter);
  return NULL;        
}
void removeBookById(int id) {
  std::list<Book>::iterator iter;
  for(iter=books.begin();iter!=books.end();++iter)
    if(iter->getId()==id)
        break;
  if(iter!=books.end()) books.remove(iter);       
}
double findAveragePrice() {
  double sum=0;
  std::list<Book>::iterator iter;
  for(iter=books.begin();iter!=books.end();++iter)
     sum += iter->getPrice();
  return sum/books.size();
}
Book& findBookWithMaxPages() {
  std::list<Book>::iterator iter=books.begin();
  auto maxIter = iter;
  double maxPages=iter->getPrice();
  ++iter;
  for(;iter!=books.end();++iter)
    if(iter->getPages() > maxPages)
        maxPrice = iter->getPages();
  //TODO: return book with max pages
  return *maxIter;
}
std::list<Book>  findAllBooksByAuthor(std::string author) {
  std::list<Book> results;
  std::list<Book>::iterator iter;
  for(iter=books.begin();iter!=books.end();++iter)
    if(iter->getAuthor()==author)
       results.push_back(*iter);
  return results;
}

//std::list<Book> results;
//fetchAllBooksByAuthor(author,results);
//void fetchAllBooksByAuthor(std::string author, std::list<Book>& results);

















                
                
                
                


