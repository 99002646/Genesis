#include<iostream>
#include<string>
#include<list>
#include<gtest/gtest.h>
#include"book.h"
#include"library.h"
#include"library.cpp"
namespace {

class LibraryTest : public ::testing::Test {

protected:
  void SetUp() { 
    libs.addBook(1,"bsf","shgfh","wegfuiwg",46.38,437);
    libs.addBook(2,"ad","addddddS","wZcx",243.38,34);
    libs.addBook(3,"sdgx","agjhjkfhjk","weeaagfuiwg",6.3438,47);

  }
  void TearDown() {}
  Library libs;
 
};

TEST_F(LibraryTest, AddBookTest) {
  libs.addBook(4, "sdgs", "dfdbbx","vknjbnkfng",65.64,100);
}
TEST_F(LibraryTest, RemoveBookTest) {
  libs.removeBook(2);
  EXPECT_EQ(NULL, libs.findbook(2));
  EXPECT_EQ(2,libs.countbooks(5));
  EXPECT_EQ(1,libs.booksrange(40,50));
  EXPECT_EQ(2,libs.countAll());
  //EXPECT_EQ(NULL, libs.getId());
}
}
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
