#!/usr/bin/env python

import subprocess
import time
import os
import thread
import signal





delay = 8
play = 0



# -p40 -s160

def command_single(process, inputcommand):
	global play
	play = 1
	p = subprocess.Popen(inputcommand, stdout=subprocess.PIPE, shell=True)
	(output, err) = p.communicate()
   
	p.wait()
	print("OK")
	play = 0


def thread_single(process, yolla):
    try:
        thread.start_new_thread( command_single, (process, yolla,) )
    except:
        print "Error: unable to start thread"



for i in range(5):

	if play == 0:
		print("START")
		a = "Aleykum selam sen nasIlsIn"   
		c = 'espeak -vtr -k5 -s150 "%s" 2>>/dev/null' % a #speak aloud
		thread_single("Yeni",c)

		while 1:
			if play == 0:
				time.sleep(delay)
				break

		print "END"


