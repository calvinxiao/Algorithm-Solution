#Problem ID: 1382
#Submit Time: 2012-10-25 13:51:44
#Run Time: 10
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

#sys.stdin = open("a.txt", "r")

TC = getint()
for tc in xrange(TC):
    n = getint()
    #print n
    p = 0
    while 1:
        if n % (2**p) == 0:
            o = n / (2**p)
            if o % 2 == 1:
                print o, p
                break
        p += 1
