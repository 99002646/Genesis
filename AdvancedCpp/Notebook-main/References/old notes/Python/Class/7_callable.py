'''
object() >> object.__call__(self)   # object define with __call__

# Check for callable functions with arguments
'''



import os
os.system('clear')    #Clear terminal 

#''' Simple program to understand callable files

class Person:
    i = 0

    def __init__(self, id):
        self.i = id


p = Person(10)
print('Person Class is callable = ', callable(Person))
print('Person object is callable = ', callable(p))


#'''


''' Calling objects with arguments

class Employee:
    id = 0
    name = ""

    def __init__(self, i, n):
        self.id = i
        self.name = n

    def __call__(self, i, nm):
        print(id)
        print(nm)
    
    def show(self):
        print('Id: ',self.id)
        print('Name: ',self.name)


e = Employee(10, 'Pankaj')  # creating object
e1 = Employee
e.show()  # printing object
print(e())  # calling object
print(e())  # calling object
print(callable(e))

#'''