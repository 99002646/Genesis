#include "leapyear.h"
#include <gtest/gtest.h>
namespace {
TEST(LeapTest, LeapYears) {
  EXPECT_EQ(1, IsLeapYear(1996));
  EXPECT_EQ(1, IsLeapYear(2012));
  EXPECT_EQ(1, IsLeapYear(2016));
}
TEST(LeapTest, NonLeapYears) {
  EXPECT_EQ(0, IsLeapYear(1997));
  EXPECT_EQ(0, IsLeapYear(2015));
  EXPECT_EQ(0, IsLeapYear(1947));
}
TEST(LeapTest, Centuries) {
  EXPECT_EQ(1, IsLeapYear(2000));
  EXPECT_EQ(1, IsLeapYear(1900));
  EXPECT_EQ(0, IsLeapYear(2100));
  EXPECT_EQ(1, IsLeapYear(1600));
}
TEST(LeapTest, InvalidYear) {
  EXPECT_EQ(-1, IsLeapYear(-1900));
  EXPECT_EQ(-1, IsLeapYear(-1500));
}
}
