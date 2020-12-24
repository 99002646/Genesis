# Simple example of using general timer objects. This is used to update
# the time placed in the title of the figure.
import matplotlib.pyplot as plt
import numpy as np
from datetime import datetime
'''
def update_title(axes):
    axes.figure.canvas.draw()
'''

fig, ax = plt.subplots()
time = np.arange(0, 10, 0.1)
amplitude   = np.sin(time)
ax.plot(time,amplitude)

# Create a new timer object. Set the interval to 100 milliseconds
# (1000 is default) and tell the timer what function should be called.
timer = fig.canvas.new_timer(interval=100)
#timer.add_callback(update_title, ax)
timer.start()

 #Or could start the timer on first figure draw
def start_timer(evt):
    timer.start()
    fig.canvas.mpl_disconnect(drawid)
drawid = fig.canvas.mpl_connect('draw_event', start_timer)

plt.show()



