'''
object.{intance methods}
* user defined methods or operations for a class
* Declared Methods should have atleast one arguments
* __init__ attribute is constructor for instance variables
* Instance Variable
    - self is default arg acts as pointer to intance variables
    - i is instance level variable has instance scope
    - self.i is the way to access the instance variable
    - call method follows MRO 1st __init__ attribute >> instance methods sequentialy
'''
import os
os.system("clear")

class test():
    #uncomment from trail 3
    '''
    def __init__(self):  #Constructor(Intiallization)
        self.i = 10  
    #'''    
    def display(self):    #Creates instance variables
        self.i = 20             # i is over written in the display method
        print('Value of i:',self.i)

    def show_i(self):  # calls instance variables
        print('Value of show.i:',self.i)


# Main Flow
t1 = test()
print('List of instance Variables:',t1.__dict__)    #No initial instance variables  

#  trial 1 - intro
'''
t1.display()   # t1.display(t1)   ,1st call
print(t1.__dict__)
t1.show_i() 
print(t1.__dict__)
#'''

# trail 2 - without constructor
''' 
t1.show_i()   # results error bcz no instance variables created yet (goto trail3)
#'''

# trail 3 - with constructor
'''add __init__ attribute to the class and check the variables list
t1.show_i()   # Now no error
#'''

# trial 4 overrite instance variable using methods
#''' 
t1.show_i() 
t1.display() 
#'''



