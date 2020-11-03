
#include "stlpoint.h"
#include"point.h"
#include <gtest/gtest.h>
namespace {

class PointTest : public ::testing::Test {
  
  protected:
    void SetUp() { //override {
	pointt.addPoint(3,0);
	pointt.addPoint(2,2);
	pointt.addPoint(1,2);

    }
    void TearDown()
    {
    }
    STLPoint pointt;
}; 
   
TEST_F(PointTest,CountingPoints) {
  EXPECT_EQ(3,pointt.countAllPoints());
}
TEST_F(PointTest,CountingPointsInQuadrant) {
  EXPECT_EQ(2,pointt.countAll(Q1));
}
TEST_F(PointTest,CountPointOnCircle) {
  EXPECT_EQ(1,pointt.displayPointOnCircle(3));
}
TEST_F(PointTest,CountPointinCircle) {
   EXPECT_EQ( 2,pointt.displayPointinCircle(3));
  
}

}


