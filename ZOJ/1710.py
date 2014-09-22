#Problem ID: 1710
#Submit Time: 2013-03-09 17:32:40
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return input()

def getints():
	return map(int, raw_input().split())

def getlist():
    return raw_input().split()

#sys.stdin = open("0.in", "r")

while 1:
    h, u, d, f = [float(n) for n in getints()]
    uf = u * f / 100
    if h == 0.0:
        break
    init = 0.0
    day = 0
    while 1:
        day += 1
        init += u
        if init > h:
            break
        init -= d
        if init < 0.0:
            break
        u -= uf
        if u < 0.0:
            u = 0.0
        #print 'day %d init %f u %f h %f' % (day, init, u, h)
    if init > h:
        print 'success on day %d' % day
    else:
        print 'failure on day %d' % day
        
