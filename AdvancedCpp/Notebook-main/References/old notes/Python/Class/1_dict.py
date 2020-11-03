'''
objectName.__dict__    # Attributes
for instance level variables
It is a special attribute to get the variables list in the class and object

'''
class test():
    c = 0        #Empty Class  

#<objName> = <ClassName>();     #object declaration
t1 = test()         

print(test.__dict__)        # Class level
print(t1.__dict__)          # Object level





