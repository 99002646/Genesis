#functions
#callable classes
#inheriting Thread class-Java

import threading;
import time;

def my_thread(a):
    print("child id:",threading.currentThread().name);
    for i in range(5):
        print("In my_thread function:",i);
        time.sleep(1);

class MyThread():
    def __call__(self,a,b):
        print("call received:",a,b);
        for i in range(5):
            print("tO thread fun:",i);
            time.sleep(1);



#print("main started");
#print("main id:",threading.currentThread().name);
my_thread=MyThread();
th1=threading.Thread(target=my_thread,args=(10,20),name="CHILDTHREAD");
th1.start();
for i in range(5):
    print("tO main fun:",i);
    time.sleep(1);

