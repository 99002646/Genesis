import datetime as dt
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(1,1,1)
fs = 50000
x = np.arange(fs)
xlist=x.tolist()
input_volt = 50
N =fs
yout = (input_volt + ((0.01*input_volt*np.random.randn(N))))
ylist=yout.tolist()

def animate(i,xlist,ylist):
    xlist=xlist[-5000:]
    ylist=ylist[-5000:]
    ax.clear()
    ax.plot(xlist,ylist)
    plt.xticks(rotation=45, ha='right')
ani = animation.FuncAnimation(fig, animate, fargs=(xlist,ylist),interval=1000)
plt.show()

    
    