import numpy as np
import matplotlib.pyplot as plt
import scipy, pylab

plt.axes()
circle=plt.Circle((0, 0), radius=1, fc='w')
plt.gca().add_patch(circle)
plt.yticks(np.arange(0, 3, 0.25))
plt.xticks(np.arange(0, 5, 0.50))
plt.axis('scaled')
plt.show()