#include "book.h"
#include <vector>
#include <list>
typedef enum ErrorType {
  SUCCESS,
  FAILURE
}error_t;

class Library {
  std::vector<Book> books;

public:
  error_t addBook(int id, std::string title, std::string author,
               std::string publisher, double price, int pages) {
    /*Book temp(id, title, author, publisher, price, pages);
    books.push_back(temp);*/

    // books.push_back(Book(id, title, author, publisher, price, pages));
    books.emplace_back(id, title, author, publisher, price, pages);
    return SUCCESS;
  }
  error_t displayAll() {
    //std::vector<Book>::iterator iter;
    /*auto iter = books.begin();
    for (iter = books.begin(); iter != books.end; ++iter)
      iter->display();*/
    for(Book& ref:books)    //auto& ref : books
      ref.display();
    return SUCCESS;
  }
  Book* findBookById(int keyId) {
    std::vector<Book>::iterator iter;
    for (iter = books.begin(); iter != books.end; ++iter)
      if (iter->getId() == keyId)
        return &(*iter);
    return nullptr;
  }
  double findAveragePriceOfBook() {
    std::vector<Book>::iterator iter;
    double totalPrice = 0;
    for (iter = books.begin(); iter != books.end; ++iter)
       totalPrice += iter->getPrice();
    return totalPrice / books.size();
  }
  /*void printAllBookByAuthor(std::string author) {
    for (auto iter = books.begin(); iter != books.end; ++iter)
      if (iter->getAuthor() == author)
          iter->display();
  }*/
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