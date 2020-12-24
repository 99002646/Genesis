import numpy as np
from matplotlib.lines import Line2D
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from math import pi
from scipy.signal import butter, lfilter
import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import freqz
from scipy.ndimage import gaussian_filter1d
import math
from numpy.compat.py3k import long
 
fs = 5000.0
lowcut = 40.0
highcut = 70.0
o = 3
 
def butter_bandpass(lowcut, highcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    high = highcut / nyq
    b, a = butter(order, [low, high], btype='band')
    return b, a
 
def butter_bandpass_filter(data, lowcut, highcut, fs, order=5):
    b, a = butter_bandpass(lowcut, highcut, fs, order=order)
    y = lfilter(b, a, data)
    return y
 
# Your Parameters
input_volt=230
amp = 1.414*input_volt       #          (Amplitude)
f = 50        #      (Frequency)
fs = 5000    #     (Sample Rate)
T = 1/f
Ts = 1/fs
harmonic_amp1=0.05*amp
harmonic_amp2=0.05*amp
attenuation_factor=(amp+harmonic_amp1+harmonic_amp2)/2.5
 
# Select if you want to display the sine as a continous wave
#  True = Continous (not able to zoom in x-direction)
#  False = Non-Continous  (able to zoom)
continous  = True
 
x = np.arange(fs)
#print(x)
y= [ ((amp*np.sin(2*np.pi*f * (i/fs)))+(0.05*amp*np.sin(6*pi*f * (i/fs)))+(0.05*amp*np.sin(12*pi*f * (i/fs))))*(1/attenuation_factor) for i in x ]
adc=[((y[i]/5)*65536)+(32768) for i in x]
for i in x:
    #print((y[i]))
    #adc = ((y[i]/5)*65536)+(32768)
   
    #print(adc)
    op1 = 32768 + butter_bandpass_filter(adc, lowcut, highcut, fs, order=o)
    #print(op1.shape)
    op2 = gaussian_filter1d(op1, 4)
    #print(math.ceil(op2[i]))
#adc=((y/10)*65536)+(32768)
 
    
class Scope(object):
    def __init__(self, ax, maxt=2*T, dt=Ts):
        self.ax = ax
        self.dt = dt
        self.maxt = maxt
        self.tdata = [0]
        self.ydata = [0]
        self.line = Line2D(self.tdata, self.ydata)
        self.ax.add_line(self.line)
        self.ax.set_ylim(-440,440)
        self.ax.set_xlim(0, self.maxt)
 
    def update(self, y):
        lastt = self.tdata[-1]
        if continous :
            if lastt > self.tdata[0] + self.maxt:
                self.ax.set_xlim(lastt-self.maxt, lastt)
 
        t = self.tdata[-1] + self.dt
        self.tdata.append(t)
        self.ydata.append(y)
        self.line.set_data(self.tdata, self.ydata)
        return self.line,
mode = 1 # 1 For AC, 0 DC
RangeAC = attenuation_factor*2.5*2
RangeDC = attenuation_factor*5
inputs = 32768
op = 0
if(mode == 0):
    opc = [(op1[i]/65536)*RangeDC for i in x]
 
if(mode == 1):
    opc = [((op1[i]-32768)/65536)*RangeAC for i in x]
def sineEmitter():
    for i in x:
        #inputs = op2[i]
        print(opc[i])
        yield (opc[i])
 
fig, ax = plt.subplots()
scope = Scope(ax)
 
# pass a generator in "sineEmitter" to produce data for the update func
ani = animation.FuncAnimation(fig, scope.update, sineEmitter, interval=10,
                              blit=True)
 
plt.show()