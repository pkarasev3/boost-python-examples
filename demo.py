#!/usr/bin/env python

import sys, subprocess, fcntl, os
import tty, termios, time
def getch():
    sys.stdout.flush()
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    tty.setraw(sys.stdin.fileno())
    ch = sys.stdin.read(1)
    termios.tcsetattr(fd, termios.TCSANOW, old_settings)

py = subprocess.Popen(['/usr/bin/python', '-u', '-i'], 
                      stdin=subprocess.PIPE,
                      stdout=None#subprocess.PIPE)
                      )
#fd = py.stdout.fileno()
#fl = fcntl.fcntl(fd, fcntl.F_GETFL)
#fcntl.fcntl(fd, fcntl.F_SETFL, fl | os.O_NONBLOCK)

f = open(sys.argv[1])

# def color(t, c):
#         return chr(0x1b)+"["+str(c)+"m"+t+chr(0x1b)+"[0m"
# def white(t):
#         return color(t, 37)
# def yellow(t):
#         return color(t, 33)

time.sleep(1)
sys.stdout.flush()

for ln in f:
    getch()
    print ln,

    py.stdin.write(ln)
    time.sleep(0.1)
