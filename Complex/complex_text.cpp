#include"complex.cpp"
#include<iostream>
#include<gtest/gtest.h>
TEST(a,b){
	Complex<int> p1(1,1);
	ASSERT_EQ(1, p1.real());
	ASSERT_EQ(1, p1.image());
	std::string ExpectedOut="1,1";
	testing::internal::CaptureStdout();
	p1.display();
	std::string ActualOut = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
