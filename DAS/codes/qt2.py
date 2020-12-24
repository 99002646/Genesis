import sys 
from PyQt5.QtWidgets import QDialog, QApplication, QPushButton, QVBoxLayout 
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas 
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar 
import matplotlib.pyplot as plt 
import random 

from PyQt5 import QtWidgets, QtCore
from pyqtgraph import PlotWidget, plot
import pyqtgraph as pg
import sys  # We need sys so that we can pass argv to QApplication
import os
from random import randint




# main window 
# which inherits QDialog 
class Window(QDialog): 
       
    # constructor 
    def __init__(self, parent=None): 
        super(Window, self).__init__(parent) 
   
        # a figure instance to plot on 
        self.figure = plt.figure() 
   
        # this is the Canvas Widget that  
        # displays the 'figure'it takes the 
        # 'figure' instance as a parameter to __init__ 
        self.canvas = FigureCanvas(self.figure) 
   
        # this is the Navigation widget 
        # it takes the Canvas widget and a parent 
        self.toolbar = NavigationToolbar(self.canvas, self) 
   
        # Just some button connected to 'plot' method 
        self.button = QPushButton('Plot') 
           
        # adding action to the button 
        self.button.clicked.connect(self.plot) 
   
        # creating a Vertical Box layout 
        layout = QVBoxLayout() 
           
        # adding tool bar to the layout 
        layout.addWidget(self.toolbar) 
           
        # adding canvas to the layout 
        layout.addWidget(self.canvas) 
           
        # adding push button to the layout 
        layout.addWidget(self.button) 
           
        # setting layout to the main window 
        self.setLayout(layout) 
   
    # action called by thte push button 
    def plot(self): 
           
        # random data 
        data = [random.random() for i in range(10)] 
   
        # clearing old figure 
        self.figure.clear() 
   
        # create an axis 
        ax = self.figure.add_subplot(111) 
   
        # plot data 
        ax.plot(data, '*-') 
   
        # refresh canvas 
        self.canvas.draw() 



class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)

        self.graphWidget = pg.PlotWidget()
        self.setCentralWidget(self.graphWidget)

        self.x = list(range(100))  # 100 time points
        self.y = [randint(0,100) for _ in range(100)]  # 100 data points

        self.graphWidget.setBackground('w')

        pen = pg.mkPen(color=(255, 0, 0))
        self.data_line =  self.graphWidget.plot(self.x, self.y, pen=pen)

        self.timer = QtCore.QTimer()
        self.timer.setInterval(50)
        self.timer.timeout.connect(self.update_plot_data)
        self.timer.start()

    def update_plot_data(self):

        self.x = self.x[1:]  # Remove the first y element.
        self.x.append(self.x[-1] + 1)  # Add a new value 1 higher than the last.

        self.y = self.y[1:]  # Remove the first 
        self.y.append( randint(0,100))  # Add a new random value.

        self.data_line.setData(self.x, self.y)  # Update the data.
# driver code 
if __name__ == '__main__': 
       
    # creating apyqt5 application 
    app = QApplication(sys.argv) 
   
    # creating a window object 
    main = Window() 
       
    # showing the window 
    main.show() 
   
    # loop 
    sys.exit(app.exec_())


app = QtWidgets.QApplication(sys.argv)
w = MainWindow()
w.show()
sys.exit(app.exec_())