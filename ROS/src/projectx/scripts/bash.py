#!/usr/bin/env python

import subprocess
import time

p = subprocess.Popen(["./ProjectX/Motion/Linux/project/rme/rme"], bufsize=2048, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)


print("1")

time.sleep(4)

p.stdin.write('exit')
p.stdin.write('\n')

print "bitti"