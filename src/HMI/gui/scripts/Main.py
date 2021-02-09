import numpy as np
import time

import rospy
from geometry_msgs.msg import TwistStamped

from GUI import Ui_Dialog

import sys
from PyQt5.QtWidgets import QDialog, QApplication
from PyQt5.QtWidgets import QFileDialog,QMessageBox, QDial
from PyQt5.QtGui import QCursor
from PyQt5.QtCore import Qt

class main_window(QDialog):
    def __init__(self):
        super(main_window,self).__init__()

        rospy.Subscriber('/cmd_vel_fb', TwistStamped, self.fb_cb)

        self.steer = 0
        self.speed = 0

        #back to standard code
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)
        self.assign_widgets()

        self.show()

    def fb_cb(self,msg):
        self.speed = msg.twist.linear.x 
        self.steer = msg.twist.angular.z 
        print('Callback')

    
    def run(self):
        while not rospy.is_shutdown():
            self.ui.steer_lcd.display(self.steer)
            self.ui.speed_lcd.display(self.speed)
            self.repaint()


    def assign_widgets(self):
        self.ui.start_but.clicked.connect(self.run)
        self.ui.exit_but.clicked.connect(self.ExitApp)

    def ExitApp(self):
        app.exit()
    
    def stop(self):
        self.stop = True

if __name__ == "__main__":
    app = QApplication.instance()
    if not app:
        app = QApplication(sys.argv)
    app.aboutToQuit.connect(app.deleteLater)
    main_win = main_window()
    sys.exit(app.exec_())