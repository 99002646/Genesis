#include "book.h"
#include <vector>
#include <list>
#include <algorithm>
typedef enum ErrorType {
  SUCCESS,
  FAILURE
}error_t;
bool compareAuthor(const Book& r1, const Book& r2) {
  return r1.getAuthor() < r2.getAuthor();
}
bool comparePages(const Book& r1, const Book& r2) {
  return r1.getPages() < r2.getPages();
}
class Library {
  std::vector<Book> books;

public:
  error_t addBook(int id, std::string title, std::string author,
               std::string publisher, double price, int pages) {
    // books.push_back(Book(id, title, author, publisher, price, pages));
    books.emplace_back(id, title, author, publisher, price, pages);
    return SUCCESS;
  }
  error_t displayAll() {
    std::vector<Book>::iterator iter;
    for (iter = books.begin(); iter != books.end; ++iter)
      iter->display();
    //for(Book& ref:books)    
      //ref.display();
    return SUCCESS;
  }
  Book* findBookById(int keyId) {
    Book keyObj(keyId,"","","",0,0);
    std::vector<Book>::iterator iter;
    iter = std::find(books.begin(), books.end(),keyObj); //operator==
  }
  ErrorType sortBooksByTitle() {
    std::sort(books.begin(),books.end());
  }
  ErrorType sortBooksByAuthor() {
    std::sort(books.begin(),books.end(), compareAuthor);
  }
  double findAveragePriceOfBook() {
    std::vector<Book>::iterator iter;
    double totalPrice = 0;
    for (iter = books.begin(); iter != books.end; ++iter)
       totalPrice += iter->getPrice();
    return totalPrice / books.size();
  }
  Book* findBookWithMaxPrice() {

  }
  
  Book* findBookWithMinPriceByPublisher(std::string publisher) {

  }
  double findAveragePriceOfBook(std::string publisher) {

  }
  int countBooksByPriceRange(double pmin, double pmax) {

  }
  int countBooksWithinPriceLimitByAuthor(double pmax,std::string author ) {

  }

  /*std::list<Book> findAllBooksByAuthor(std::string author) {
     std::list<Book> result;
     for (auto iter = books.begin(); iter != books.end; ++iter)
      if (iter->getAuthor() == author)
        result.push_back(*iter);
    return result;
  }*/
  int findAllBooksByAuthor(std::string author, std::list<Book>& results) {
    for (auto iter = books.begin(); iter != books.end; ++iter)
      if (iter->getAuthor() == author)
        results.push_back(*iter);
    return SUCCESS;
  } //fetch results, thru params passed by reference
};

/**
 * std::list<Book> bookset = library.findAllBooksByAuthor("Scott");
 * std::list<Book> bookset;
 * library.findAllBooksByAuthor("Scott", bookset);
 * bookset is not empty *  
 */ 