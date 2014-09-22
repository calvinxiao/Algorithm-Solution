#Problem ID: 2060
#Submit Time: 2012-08-16 15:00:13
#Run Time: 120
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while True:
    line = getline()
    if not line:
        break
    n = int(line)
    flag = False
    if n > 1 and (n-2) % 4 == 0:
        flag = True
    if flag:
        print 'yes'
    else:
        print 'no'
        

