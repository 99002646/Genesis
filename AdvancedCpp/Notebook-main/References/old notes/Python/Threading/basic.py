import threading
import os
os.system('clear')

'''
def my_thread():
    print("In my thread function")

print("Main Started")
th1 = threading.Thread(target=my_thread)
th1.start()
print("Main end")


#'''

def my_thread():
    for i in range(5):
        print("In my thread function:" ,i)

print("Main Started")
th1 = threading.Thread(target=my_thread)
th1.start()
print("Main end")