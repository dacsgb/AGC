#!/usr/bin/env python3

import numpy as np
import time

import rospy
from automotive_platform_msgs.msg import Speed, SteeringCommand

from GUI import Ui_Dialog

import sys
from PyQt5.QtWidgets import QDialog, QApplication
from PyQt5.QtWidgets import QFileDialog,QMessageBox, QDial
from PyQt5.QtGui import QCursor
from PyQt5.QtCore import Qt, QTimer

class Node():
    def __init__(self):
        self.steer_sub = rospy.Subscriber('/CMD/steer', SteeringCommand, self.steer_cb)
        self.speed_sub = rospy.Subscriber('/CMD/speed', Speed,self.speed_cb)

        self.steer = 0
        self.speed = 0

        self.rate = rospy.Rate(50)

    def speed_cb(self,msg):
        self.speed = msg.speed
    
    def steer_cb(self,msg):
        self.steer = msg.steering_wheel_angle

class main_window(QDialog):
    def __init__(self,node):
        super(main_window,self).__init__()

        self.node = node

        #back to standard code
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)
        self.assign_widgets()

        self.show()

        self.timer = QTimer()
        self.timer.timeout.connect(self.update)
        self.timer.start(0.5)

    def assign_widgets(self):
        self.ui.start_but.clicked.connect(self.update)
        self.ui.exit_but.clicked.connect(self.ExitApp)

    def update(self):
        self.ui.steer_lcd.display(np.rad2deg(self.node.steer))
        self.ui.speed_lcd.display(self.node.speed)
        self.show()

    def ExitApp(self):
        app.exit()
    
    def stop(self):
        self.stop = True

if __name__ == "__main__":
    rospy.init_node("dashboard")
    Reader = Node()
    app = QApplication.instance()
    if not app:
        app = QApplication(sys.argv)
    app.aboutToQuit.connect(app.deleteLater)
    main_win = main_window(Reader)
    sys.exit(app.exec_())