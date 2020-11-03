'''
object.{magicMethod}
* Operator overloading >> object + object
* Operations like :
  - Normal Operations
    + __add__
    - __sub__
    / __truediv__
    // __floordiv__
    <= __le__
    >= __ge__

  - Reflexive 
    < __lt__
    > __gt__ 
    == __eq__
    != __ne__

* methods with return call to read method
'''

class Number():
  
    def __init__(self,n=0):  #basic instance level,#constructor 
        self.n = n
  
    def show(self):  # calls instance variables
        print('Value of show.n:',self.n)

    def __add__(self,other):
       
        ''' trail1 
        temp = self.n + other.n
        return temp
        #'''
       
        ''' trail 2 
        self.n = self.n + other.n
        #'''

        ''' trail3
        temp = Number()
        temp.n = self.n + other.n
        return temp
        #'''

        '''trial4      #Other is integer
        self.n = self.n + other
        #'''

        #'''trial 5  code for  trials 3,4
        if( isinstance(other, Number) ):
            temp = Number()      #trial 3
            temp.n = self.n + other.n
            return temp
        elif(isinstance(other, int) ):      #trial 4
            self.n = self.n + other
        #'''

    def __lt__(self,other):     # < and > operation
        return self.n < other.n



n1 = Number(10)
n2 = Number(20)

''' Trail 1 (obj,obj) >> integer(return)
n3 = n1+n2      # n1.__add__(n1,n2)
print(n3)
#'''

''' Trial 2 (obj,obj) >> update in self
n1+n2
n1.show()
#'''

''' Trial 3 (obj,obj) >> obj(return)
n3 = n1+n2
n3.show()
#'''

''' trial 4 (obj,int) >> self update
n1 + 15          # n1.__add__(n1,15)
n1.show()
#'''

#''' Trial relational attributes
print(n1<n2)
print(n1>n2)   #will work due to reflexive (No Attribute Defined)
#'''

