#
import threading;
import time;

def my_thread():
    for i in range(5):
        print("in my_thread...");
        time.sleep(1);

print("main start");
th1=threading.Thread(target=my_thread);
th1.start();
th1.join();
print("main end");