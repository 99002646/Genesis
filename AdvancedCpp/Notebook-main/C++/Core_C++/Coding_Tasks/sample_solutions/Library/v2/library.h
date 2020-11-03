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
    std::for_each(books.begin(), books.end(), [](Book& ref) {
      ref.display();
    });
    return SUCCESS;
  }
  Book* findBookById(int keyId) {

     auto iter = std::find_if(books.begin(), books.end(), 
                    [keyId](Book& ref) {
       return ref.getId() == keyId;
     });
     return &(*iter);
  }  
  ErrorType sortBooksByTitle() {
    std::sort(books.begin(),books.end(), [](const Book& r1,
                                          const Book& r2) {
      return r1.getTitle() < r2.getTitle();
    });
  }
  /*ErrorType sortBooksByAuthor() {
    std::sort(books.begin(),books.end(), compareAuthor);
  }*/
  double findAveragePriceOfBook() {
    std::vector<Book>::iterator iter;
    double totalPrice = 0;
    for (iter = books.begin(); iter != books.end; ++iter)
       totalPrice += iter->getPrice();
    return totalPrice / books.size();
  }
  Book* findBookWithMaxPrice() {
    auto res =std::max_element(books.begin(),books.end(), [](const Book& r1,
                                          const Book& r2) {
      return r1.getPrice() < r2.getPrice();
    });
  }
  
  Book* findBookWithMinPriceByPublisher(std::string publisher) {

  }
  double findAveragePriceOfBook(std::string publisher) {

  }
  int countBooksByPriceRange(double pmin, double pmax) {
    std::count_if(books.begin(),books.end(), [pmin,pmax](Book& ref) {
        return ref.getPrice() > pmin && ref.getPrice() < pmax;
    });
  }
  int countBooksWithinPriceLimitByAuthor(double pmax,std::string author ) {
     int count=0;
     std::for_each(books.begin(),books.end(),[pmax,author,&count](const Book& ref) {
        if(ref.getAuthor()==author && ref.getPrice() < pmax) 
            count++;
     });
     return count;
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
