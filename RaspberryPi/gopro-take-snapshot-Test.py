#!/usr/bin/python3.6

# imports
from goprocam import GoProCamera
import sys, shutil, os

# script must be executed in gopro-py-api directory
os.chdir("/home/pi/gopro-py-api")

# create the GoPro object
cam = GoProCamera.GoPro()

# take one photo, get its URL
cam.take_photo() # default : delay = 1sec

cam.delete("last")
#cam.power_off()

