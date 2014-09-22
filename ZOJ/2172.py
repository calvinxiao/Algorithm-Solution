#Problem ID: 2172
#Submit Time: 2012-09-10 14:20:47
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

tc = 0
while 1:
    n = getint()
    if not n:
        break
    tc += 1
    print 'SET %d' % tc
    a = []
    for i in xrange(n):
        a.append(getline().strip())
    for i in xrange(0, n, 2):
        print a[i]
    for i in xrange(n - 1, -1, -1):
        if i % 2 == 1:
            print a[i]
    
