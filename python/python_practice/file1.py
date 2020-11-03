
l=(1);
print(l);
class MyException(Exception):

    def __init__(self.msg):
        #self.args=(msg);
    
#print("befor try");
try:
    L=[1,2,3,4,5]
    print("befor except");
    #test();
    #file=open("t.txt","r");
    #L[3]=77;
   
    myEx=MyException();
    raise myEx;
    #t();
    print("after except");
except IndexError as ex:
    print("except: before file opened",ex.args);
except FileNotFoundError as ex:
    print("except:",ex.args);
except Exception as ex:
    print("Main except:",ex.args);
'''
finally:
    print("Finally block");
'''

print("after try");

