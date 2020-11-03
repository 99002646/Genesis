#include "contact.h"
#include "address.h"
#include <gtest/gtest.h>
namespace {

class ContactTest : public ::testing::Test {

  protected:
    void SetUp() { //override {
        addr.addContact( "william"," thomos","7845123695","8574123659" );
        addr.addContact( "john","marry","9874512635","7685412395");
        addr.addContact( "saint","john","9478512365","8457123695");
    }
    void TearDown() {}
    Address addr;
};
TEST_F(ContactTest,CountContacts) {
  EXPECT_EQ(3,addr.countAll());
}

TEST_F(ContactTest,AddContact)
{
  addr.addContact("ram","kumar","9848022335","9848022336"  );
  EXPECT_EQ(4,addr.countAll());
  contact *ptr=addr.findContactBypnum( "9848022335" );
  EXPECT_NE(nullptr, ptr);
  EXPECT_STREQ("ram", ptr->getfirstname().c_str());

}
TEST_F(ContactTest,RemoveContact) {
  addr.removeContactBypnum( "9874512635" );
  EXPECT_EQ(2,addr.countAll());

}
TEST_F(ContactTest, findContactWithMatchname) {
  contact *ptr=addr.findContactWithMatchname("saint","john");
    EXPECT_NE(nullptr, ptr);
  EXPECT_EQ("saint",ptr->getfirstname());
   EXPECT_EQ("john",ptr->getlastname());
    EXPECT_EQ("9478512365",ptr->getprimaryno());
    
}
TEST_F(ContactTest, findContactBypnum) {
  contact *ptr=addr.findContactBypnum("9478512365");
    EXPECT_NE(nullptr, ptr);
  EXPECT_EQ("saint",ptr->getfirstname());
   EXPECT_EQ("john",ptr->getlastname());
    EXPECT_EQ("9478512365",ptr->getprimaryno());
    
}
}
