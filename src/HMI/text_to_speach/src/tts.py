#!/usr/bin/python3

import pyttsx3
import rospy

from std_msgs.msg import String

class TTS():
    def __init__(self):
        self.engine = pyttsx3.init()
        self.engine.setProperty('rate',175)

        self.text_sub = rospy.Subscriber("/text",String,self.text_cb)
        self.rate = rospy.Rate(5)

    def text_cb(self,msg):
        self.say(msg.data)

    def say(self,text):
        self.engine.say(text)
        self.engine.runAndWait()
    
    def run(self):
        self.rate.sleep()

if __name__ == "__main__":
    rospy.init_node("tts")

    Node = TTS()
    Node.say("All systems are operational")