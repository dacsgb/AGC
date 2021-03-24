#!/usr/bin/python3


import pyttsx3
import time


engine = pyttsx3.init()
engine.setProperty('rate',250)
engine.say("FUCK")
engine.runAndWait() 