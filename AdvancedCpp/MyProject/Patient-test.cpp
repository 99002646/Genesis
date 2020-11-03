#include "Appointment.h"
#include "Patient.h"
#include <gtest/gtest.h>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
namespace {
/*class AppointmentTest : public ::testing::Test {
public:
  Appointment *ptr;  
    void SetUp() 
  			{ 
		  		std::list<string> res;
		     		std::list<string> ::iterator iter;
		     		std::string nbrhd="";
		     		int pid=0,appid=0,gender=0,age=0,hiper=0,dia=0,alco=0,NShow=0,handicap=0;
		     		double sday=0.0,aday=0.0;
		    		std::string S,T;
		    		fstream fin;
		    		int count=1;
		    		fin.open("appointment.csv", ios::in);
		    		while(getline(fin, S))
		    		{
		    			stringstream X(S);
		    			while (getline(X, T,'\n'))
		   			 {
		   	 			res.push_back(T);
		    			 }
		   	        }
		    		iter=res.begin();
		   		 
		    		for(;iter!=res.end();++iter)
		    		{
		    			stringstream ss(*iter); 
		    			while (ss.good()) 
		    			{ 
						string substr; 
						getline(ss, substr, ','); 
						switch(count)
						{
							case 1:
								nbrhd=substr;
								break;
							case 2:
								pid=std::stoi(substr);
								break;
							case 3:
								appid=std::stoi(substr);
								break;
							case 4:
								gender=std::stoi(substr);
								break;
							case 5:
								age=std::stoi(substr);
								break;
							case 6:
								sday=std::stod(substr);
								break;
							case 7:
								aday=std::stod(substr);
								break;
							case 8:
								hiper=std::stoi(substr);
								break;
							case 9:
								dia=std::stoi(substr);
								break;
							case 10:
								alco=std::stoi(substr);
								break;
							case 11:
								handicap=std::stoi(substr);
								break;	
							case 12:
								NShow=std::stoi(substr);
																		
ptr = new Patient(nbrhd,pid,appid,gender,age,sday,aday,hiper,dia,alco,handicap,NShow);
nbrhd="",pid=0,appid=0,gender=0,age=0,sday=0.0,aday=0.0,hiper=0,dia=0,alco=0,handicap=0,NShow=0,count=0;

						}
						++count;
		    			} 
			}
 		}	  
  
void TearDown() {
    delete ptr;
  }
};*/

TEST_F(AppointmentTest, DefaultConstructor) {
	Patient ft;
  	EXPECT_EQ(0,ft.getpntid());
}

TEST_F(AppointmentTest, ParameterizedConstructor) {
	Patient *ft = dynamic_cast<Patient*>(ptr);
	EXPECT_EQ(39, ft->getpntid());
}

TEST_F(AppointmentTest, operatoroverloadingtest) {
	Patient ft1 ("a7",10,2,3,8,3.0,2.0,5,3,2,11.2,1);
	Patient ft2 ("a8",7,2,9,1,0,5.0,5,5,9,12.2,1);
	EXPECT_EQ(2,ft1+ft2);
}
}