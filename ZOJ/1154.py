#Problem ID: 1154
#Submit Time: 2012-12-18 16:34:25
#Run Time: 410
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getints():
	return [int(num) for num in getlist()]

def getlist():
    return sys.stdin.readline().strip().split()

#sys.stdin = open("0.in", "r")

TC = getint()
for tc in xrange(TC):
    getline()
    if tc:
        print ''
    while 1:
        line = getline()
        if line[0] == '0':
            break
        k, d = line.split()
        num = int(d, int(k))
        s = sum([int(x) for x in list(d)])
        if num % s == 0:
            print 'yes'
        else:
            print 'no'
