#!/usr/bin/env python3

import numpy as np
import time

import rospy
from automotive_platform_msgs.msg import Speed, SteeringCommand
from sensor_msgs.msg import BatteryState
from GUI import Ui_Dialog

import sys
from PyQt5.QtWidgets import QDialog, QApplication
from PyQt5.QtWidgets import QFileDialog,QMessageBox, QDial
from PyQt5.QtGui import QCursor
from PyQt5.QtCore import Qt, QTimer

class Node():
    def __init__(self):

        # ROS Subscribers
        self.steer_sub = rospy.Subscriber('/CMD/steer', SteeringCommand, self.steer_cb)
        self.speed_sub = rospy.Subscriber('/CMD/speed', Speed,self.speed_cb)
        self.batt_sub = rospy.Subscriber('/LLC/battery',BatteryState,self.batt_cb)
        #self.auto_sub = rospy.Subscriber('/SUP/autonomy', ,self.auto_cb)

        # Ros Publishers
        #self.auto_pub = rospy.Publisher('/HMI/autonomy',,queue_size=1)

        # Message Variables
        self.steer = SteeringCommand()
        self.speed = Speed()
        self.battery = BatteryState()
        #self.auto = Auto()

    def speed_cb(self,msg):
        self.speed = msg
    
    def steer_cb(self,msg):
        self.steer = msg

    def batt_cb(self,msg):
        self.battery= msg

    def auto_cb(self,msg):
        #self.auto = Auto()
        pass

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
        self.ui.enable_butt.clicked.connect(self.auto_enable)
        self.ui.disable_butt.clicked.connect(self.auto_disable)
    
    def auto_enable(self):
        pass

    def auto_disable(self):
        pass

    def update(self):
        self.ui.steer_lcd.display(np.rad2deg(self.node.steer.steering_wheel_angle))
        self.ui.speed_lcd.display(self.node.speed.speed)
        self.ui.battery_lcd.display(self.node.battery.voltage)
        '''
            if state = enabled:
                self.ui.auto_state.text("Enabled")
            else
                self.ui.auto_state.text("Disabled")
        '''
        
        self.show()

    def ExitApp(self):
        app.exit()
    
    def stop(self):
        self.stop = True

if __name__ == "__main__":
    rospy.init_node("dashboard")
    SubPub = Node()
    app = QApplication.instance()
    if not app:
        app = QApplication(sys.argv)
    app.aboutToQuit.connect(app.deleteLater)
    main_win = main_window(SubPub)
    sys.exit(app.exec_())