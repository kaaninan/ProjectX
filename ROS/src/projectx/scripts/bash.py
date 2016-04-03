#!/usr/bin/env python

import subprocess
import time
import os

p = subprocess.Popen(["rosrun face_recognition Fserver"], bufsize=2048, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)
time.sleep(1)
p = subprocess.Popen(["rosrun face_recognition Fclient"], bufsize=2048, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)

print("OK")

time.sleep(1)

print "bitti"