#!/usr/bin/env python3

import os
import numpy as np
import cv2
import PySpin
import matplotlib.pyplot as plt 
import sys
# import keyboard
import time 
import numpy.core.multiarray

import rospy
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge, CvBridgeError

global continue_recording 
continue_recording = True 

class Node():
    def __init__(self,serialNumber):

        self.cam = self.getCamera(serialNumber)
        print(self.cam.GetTLDeviceNodeMap())
        #self.nodemap_tldevice = self.cam.GetTLDeviceNodeMap()
        self.cam.Init()
        self.nodemap = self.cam.GetNodeMap()

        #self.image_pub = rospy.Publisher("/pointgrey/original",Image,queue_size=1)
        #self.compressed_pub = rospy.Publisher("/pointgrey/compressed",CompressedImage,queue_size=1)
        #self.comp_img = CompressedImage()
    
    def getCamera(self,serialNumber):
        system = PySpin.System.GetInstance()
        cam_list = system.GetCameras()
        cam_size = cam_list.GetSize()
        if cam_size == 0:
            cam_list.Clear()
            system.ReleaseInstance()
            print("No camera Found")
            exit
        
        for i in range(cam_size):
            cam = cam_list.GetByIndex(i)
            if cam.TLDevice.DeviceSerialNumber.GetAccessMode() == PySpin.RO:
                if (int(cam.TLDevice.DeviceSerialNumber.ToString()) == serialNumber):
                    print("Match")
                    return cam

    # def handle_close(self, evt):

    #     global continue_recording
    #     continue_recording = False

    # def testing(self,serial):
    #     system = PySpin.System.GetInstance()
    #     camList = system.GetCameras()
    #     camNum = camList.GetSize()

    #     if camNum == 0:
    #         camList.Clear()
    #         system.ReleaseInstance()
    #         print("No camera found")
    #         exit

    #     for i, cam in enumerate(camList):
    #         nodemap_tldevice = cam.GetTLDeviceNodeMap()
    #         cam.Init()
    #         nodemap = cam.GetNodeMap()

    #         sNodemap = cam.GetTLStreamNodeMap()
    #         node_bufferhandling_mode = PySpin.CEnumerationPtr(sNodemap, GetNode('StreamBufferHandlingMode'))
    #         if not PySpin.IsAvailable(node_bufferhandling_mode) or not PySpin.IsWritable(node_bufferhandling_mode):
    #             print('Unable to set stream buffer handlig mode... Aborting...')
    #             return False
        
    #         node_newestonly = node_bufferhandling_mode.GetEntryByName('NewestOnly')
    #         if not PySpin.IsAvailable(node_newestonly) or not PySpin.IsReadable(node_newestonly):
    #             print('Unbable to set stream buffer handling mode... Aborting...')
    #             return False
        
    #         node_newestonly_mode = node_newestonly.GetValue()
    #         node_bufferhandling_mode.SetIntValue(node_newestonly_mode)

    #         print('*** IMAGE ACQUISITON ***\n')
    #         try:
    #             node_acquisition_mode = PySpin.CEnumerationPtr(nodemap.GetNode('AcquisitionMode'))
    #             if not PySpin.IsAvailable(node_acquisition_mode) or not PySpin.IsWritable(node_acquisition_mode):
    #                 print('Unable to set acuqisition mode to continuous (enum retrieval). Aborting...')
    #                 return False
                
    #             node_acquisition_mode_continuous = node_acquisition_mode.GetEntryByName('Continuous')
    #             if not PySpin.IsAvailable(node_acquisition_mode_continuous) or not PySpin.IsReadable(node_acquisition_mode_continuous):
    #                 print('Unable to set acquisition mode to continuous (entry retrieval). Aborting...')
    #                 return False
                
    #             acquisition_mode_continuous = node_acquisition_mode_continuous.GetValue()

    #             node_acquisition_mode.SetIntValue(acquisition_mode_continuous)

    #             print('Acquisition mode set to continuous...')

    #             cam.BeginAcquisition()

    #             print('Acquiring images...')

    #             device_serial_number = ''
    #             node_device_serial_number = PySpin.CStringPtr(nodemap_tldevice.GetNode('DeviceSerialNumber'))
    #             if PySpin.IsAvailable(node_device_serial_number) and PySpin.IsReadable(node_device_serial_number):
    #                 device_serial_number = node_device_serial_number.GetValue()
    #                 print('Device serial number retrieved as %s...' % device_serial_number)
                
    #             print('Press enter to close the program..')

    #             fig = plt.figure(1)

    #             fig.canvas.mpl_connect('close_event', handle_close)

    #             while(continue_recording):
    #                 try:
    #                     image_result = cam.GetNextImage(1000)

    #                     if image_result.IsIncomplete():
    #                         print('Image incomplete with image status %d ...' % image_result.GetImageStatus())
                        
    #                     else:
    #                         image_data = image_result.GetNDArray()

    #                         plt.imshow(image_data, cmap = 'gray')

    #                         plt.pause(0.001)

    #                         plt.clf()

    #                         if keyboard.is_pressed('ENTER'):
    #                             print('Program is closing... ')

    #                             plt.close('all')
    #                             input('Done! Press Enter to exit...')
    #                             continue_recording = False
                        
    #                     image_result.Release()
                    
    #                 except PySpin.SpinnakerException as ex:
    #                     print('Error: %s' % ex)
    #                     return False
        
    #             cam.EndAcquisition()
        
    #         except PySpin.SpinnakerException as ex:
    #             print('Error: %s' % ex)
    #             return False
            
    #         return True 

    def run(self):
        self.cam.BeginAcquisition()

        while (True):
            image = self.cam.GetNextImage()
            if image.IsIncomplete():
                pass
            result =  image.Convert(PySpin.PixelFormat_Mono8, PySpin.HQ_LINEAR)

            cv2.imshow("Camera",result)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

            image.Release()

        self.cam.EndAcquisition()


if __name__ == "__main__":
    rospy.init_node("pointgrey_camera")
    serial = rospy.get_param("~serial_number")
    SERIAL = 18295828
    # Camera = Node(SERIAL)
    # Camera.run()