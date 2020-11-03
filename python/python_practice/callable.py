#functions
#callable classes
#inheriting Thread class-Java

import threading;
import time;
class Data():
    def __init__(self):
        self.count=0;

    def modify():
        print("data is modidfying by:",threading.currentThread().ident);
        self.count=self.count+1;



class MyThread(threading.Thread):
    def run(self):
        print("??? requesting for lock by :",threading.currentThread().ident);
        lock.acquire_lock();
        print("+++ requesting for lock by :",threading.currentThread().ident);
        #print("call received:",self.a,self.b);
        for i in range(5):
            data.modify();
            time.sleep(1);
        lock.release_lock();
        print("--- requesting for lock by :",threading.currentThread().ident);


lock=threading.Lock();
#print("main started");
#print("main id:",threading.currentThread().name);
data=Data();
th1=MyThread(data,lock);
th2=MyThread(data,lock);
th3=MyThread(data,lock);
#my_thread.start();
#th1=threading.Thread(target=my_thread,args=(10,20),name="CHILDTHREAD");
th1.start();
th2.start();
th3.start();
while(True):
    time.sleep(1);
#for i in range(5):
 #   print("tO main fun:",i);
 #   time.sleep(1);

