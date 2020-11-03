'''
class.{StaticMethod}
Object.{StaticMethod}
* Static variables or Global variables access
* methods in class to read static or global variables inside the class
* No mandatory arg
'''

import os
os.system("clear")


s_cnt = 5   #Static Variable

class test():
    cnt = 0         #Class Level variable

    def __init__(self):  #basic instance level,#constructor 
        self.i = 10
        #print('self Type :',type(self))

    def display(self):    #Creates instance variables
        self.i = 20             # i is over written in the display method
        print('Value of i:',self.i)

    def show_i(self):  # calls instance variables
        print('Value of show.i:',self.i)

    @classmethod
    def inc_count(cls):   #cls default arg for class variable pointer
        #print('cls Type :',type(cls))
        cls.cnt = cls.cnt + 1

    @staticmethod  
    def statMethd():
        #s_cnt = s_cnt + 1        # This is error bcz no write permission
        print('count (stat) = ',s_cnt)


t1 = test()
t2 = test()

test.statMethd()
t1.statMethd()
t2.statMethd()