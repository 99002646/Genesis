print("Before try")

'''wrong
L = [1,2,3,4,5]
l[7] = 77    
#'''


import os
os.system('clear')

#''' exception handling
try: 
    L = [1,2,3,4,5]
    print("before exception")
    l[7] = 77  
    print("after exception")

except IndexError:
    print("Exception : Index error")

print("after try")
#'''
