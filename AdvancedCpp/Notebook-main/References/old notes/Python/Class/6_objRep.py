'''
object >> object.__str__(self)     # String representation of object
'''

class Number():
  
    def __init__(self,n=0):  #basic instance level,#constructor 
        self.n = n
  
    def show(self):  # calls instance variables
        print('Value of show.n:',self.n)

    #''' comment to check default
    def __str__(self):   #returns only string
        return str(self.n)
    #'''


n1 = Number(10)
n2 = Number(20)
print(n1)      # n1.__str__(n1)    #prints n1 address if no __str__ attribute  
