#!/usr/bin/env python

import subprocess
import time
import os
import thread
import threading
import signal
import sys


class My_Thread(threading.Thread):

    def __init__(self):
        threading.Thread.__init__(self)
        self.process = None

    def run(self):
        print "Starting " + self.name
        cmd = [ "espeak", "-vtr", "'Selamun aleykum gencler robomental Selamun aleykum gencler robomental'"]
        self.process = p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        #print "Exiting " + self.name

    def stop(self):
        print "Trying to stop thread "
        if self.process is not None:
            self.process.terminate()
            self.process = None

thr = My_Thread()
thr.start()
time.sleep(3)
thr.stop()
#thr.join()