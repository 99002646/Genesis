'''
DC Filter(Gaussian + LP(BW) Filters)
'''
from scipy.signal import butter, lfilter
 
def butter_lowpass(lowcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    b, a = butter(order, [low], btype='low')
    return b, a
 
def butter_lowpass_filter(data, lowcut, fs, order=5):
    b, a = butter_lowpass(lowcut, fs, order = order)
    y = lfilter(b, a, data)
    return y
 
import numpy as np;
import matplotlib.pyplot as plt
import math
 
fs = 5000
lowcut = 25
o = 3
 
from scipy.ndimage import gaussian_filter1d
N = 40000
N2 = 400
 
time = np.arange(0*np.pi, 5*np.pi, 0.01)
amplitude = 100*np.sin(time)
ip = 100 + ((3*np.random.randn(N)))
i = 0
 
it = 0
while(it < N):
#while(True):
    while(i < N2):
        #print (ip[i])
        #print ("    ")
        op = butter_lowpass_filter(ip,lowcut,fs,order = o)
        op2 = gaussian_filter1d(op, 12)
        
        print (math.ceil(op2[i]))
        i = i + 1
    
    it = it + N2
plt.plot(ip, 'k', label='original data')
plt.plot(op2, '--', label='filtered')
plt.legend()
plt.grid()
plt.show()