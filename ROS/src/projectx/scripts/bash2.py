#!/usr/bin/env python

import subprocess
import time
import os

subprocess.Popen(["cd $HOME/ProjectX/Speak/Script; ./run"], bufsize=2048, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)

print("OK")