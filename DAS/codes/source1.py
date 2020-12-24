import numpy as np
from matplotlib.lines import Line2D
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from math import pi
# Your Parameters
input_volt=230#-------------input from amplitude
amp = 1.414*input_volt       #          (Amplitude)
f = 50        #      (Frequency)---------------signal frequency
fs = 5000    #     (Sample Rate)-----------------sampling freq
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
for i in x:
    print((y[i]))
    adc=int((y[i]/5)*65536)+(32768)
    print(adc)
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
        self.ax.set_ylim(-2.5, 2.5)
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
 
def sineEmitter():
    for i in x:
        yield y[i]
 
fig, ax = plt.subplots()
scope = Scope(ax)
 
# pass a generator in "sineEmitter" to produce data for the update func
ani = animation.FuncAnimation(fig, scope.update, sineEmitter, interval=10,
                              blit=True)
 
plt.show()