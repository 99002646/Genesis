'''
class.{classMethod}
objects.{class methods}
* Class level variables accessing
* Class level methods visible for objects and class(Basically Global for Class)
* Declared Methods should have atleast one arguments
* cls is Class variable pointer given as default arg
'''

import os
os.system("clear")


class test():
    cnt = 0         #Class Level variable

    def __init__(self,i=0):  #basic instance level,#constructor 
        self.i = i ;
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

t1 = test(50)
t2 = test(60)

t1.show_i()
t2.show_i()

#print(dir())  #Chechk the list of variables before
t1.inc_count()    
t2.inc_count()
test.inc_count()

#print(dir())  #Chechk the list of variables after
print('cnt value :',t1.cnt)
print('cnt value :',t2.cnt)
print('cnt value :',test.cnt)