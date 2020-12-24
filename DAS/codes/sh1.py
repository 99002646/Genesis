'''import numpy as np
import matplotlib.pyplot as plt

def on_timer(line, x, y):
    x.append(x[-1] + np.random.normal(0, 1))
    y.append(y[-1] + np.random.normal(0, 1))
    line.set_data(x, y)
    line.axes.relim()
    line.axes.autoscale_view()
    line.axes.figure.canvas.draw()

x, y = [np.random.normal(0, 1)], [np.random.normal(0, 1)]
fig, ax = plt.subplots()
line, = ax.plot(x, y, color='aqua', marker='o')

timer = fig.canvas.new_timer(interval=100, 
                             callbacks=[(on_timer, [line, x, y], {})])

timer.start()
plt.show()
'''
import numpy as np
from matplotlib.lines import Line2D
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Your Parameters
amp = 220         # 1V        (Amplitude)
f = 5        # 1kHz      (Frequency)
fs = 1000   # 200kHz    (Sample Rate)
T = 1/f
Ts = 1/fs

# Select if you want to display the sine as a continous wave
#  True = Continous (not able to zoom in x-direction)
#  False = Non-Continous  (able to zoom)
continous  = True

x = np.arange(fs)
y = [ amp*np.sin(2*np.pi*f * (i/fs)) for i in x]


class Scope(object):
    def __init__(self, ax, maxt=2*T, dt=Ts):
        self.ax = ax
        self.dt = dt
        self.maxt = maxt
        self.tdata = [0]
        self.ydata = [0]
        self.line = Line2D(self.tdata, self.ydata)
        self.ax.add_line(self.line)
        self.ax.set_ylim(-amp-10, amp+10)
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