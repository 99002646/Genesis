import threading 
def gfg(): 
    print("GeeksforGeeks\n") 

timer = threading.Timer(0.01, gfg) 
timer.start() 