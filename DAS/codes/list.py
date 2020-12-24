import numpy as np
from matplotlib.lines import Line2D
import matplotlib.pyplot as plt
import matplotlib.animation as animation

amp = 1         # 1V        (Amplitude)
f = 10        # 1kHz      (Frequency)
fs = 1000    # 200kHz    (Sample Rate)
T = 1/f
Ts = 1/fs

x = np.arange(fs)
y = [ amp*np.sin(2*np.pi*f * (i/fs)) for i in x]

list1=[0]*10
del list1[0:3]
list2=[2,4,5]
list1.extend(list2)

#x = np.arange(0,4*np.pi,0.1)   # start,stop,step
#y = np.sin(x)
print(x)

#print(y)

plt.plot(x,y)
plt.show()
'''
time = np.arange(0, 10, 0.1)
amplitude   = np.sin(time)
plt.plot(time, amplitude)
plt.show()
'''