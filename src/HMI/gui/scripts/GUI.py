# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'gui.ui'
#
# Created by: PyQt5 UI code generator 5.13.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(1290, 720)
        self.gridLayoutWidget_3 = QtWidgets.QWidget(Dialog)
        self.gridLayoutWidget_3.setGeometry(QtCore.QRect(250, 150, 611, 331))
        self.gridLayoutWidget_3.setObjectName("gridLayoutWidget_3")
        self.gridLayout_4 = QtWidgets.QGridLayout(self.gridLayoutWidget_3)
        self.gridLayout_4.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.label_2 = QtWidgets.QLabel(self.gridLayoutWidget_3)
        self.label_2.setObjectName("label_2")
        self.gridLayout_4.addWidget(self.label_2, 0, 1, 1, 1)
        self.steer_lcd = QtWidgets.QLCDNumber(self.gridLayoutWidget_3)
        self.steer_lcd.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.steer_lcd.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.steer_lcd.setSmallDecimalPoint(False)
        self.steer_lcd.setObjectName("steer_lcd")
        self.gridLayout_4.addWidget(self.steer_lcd, 1, 1, 1, 1)
        self.label = QtWidgets.QLabel(self.gridLayoutWidget_3)
        self.label.setObjectName("label")
        self.gridLayout_4.addWidget(self.label, 0, 0, 1, 1)
        self.speed_lcd = QtWidgets.QLCDNumber(self.gridLayoutWidget_3)
        self.speed_lcd.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.speed_lcd.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.speed_lcd.setSmallDecimalPoint(False)
        self.speed_lcd.setObjectName("speed_lcd")
        self.gridLayout_4.addWidget(self.speed_lcd, 1, 0, 1, 1)
        self.gridLayoutWidget = QtWidgets.QWidget(Dialog)
        self.gridLayoutWidget.setGeometry(QtCore.QRect(1120, 630, 160, 80))
        self.gridLayoutWidget.setObjectName("gridLayoutWidget")
        self.gridLayout = QtWidgets.QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.start_but = QtWidgets.QPushButton(self.gridLayoutWidget)
        self.start_but.setObjectName("start_but")
        self.gridLayout.addWidget(self.start_but, 0, 0, 1, 1)
        self.exit_but = QtWidgets.QPushButton(self.gridLayoutWidget)
        self.exit_but.setObjectName("exit_but")
        self.gridLayout.addWidget(self.exit_but, 1, 0, 1, 1)

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.label_2.setText(_translate("Dialog", "Steering"))
        self.label.setText(_translate("Dialog", "Speed"))
        self.start_but.setText(_translate("Dialog", "Start"))
        self.exit_but.setText(_translate("Dialog", "Exit"))
