#Problem ID: 2670
#Submit Time: 2012-08-10 00:23:04
#Run Time: 50
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    line = getline()
    if not line:
        break
    n = int(line)
    if n == 1:
        print 'Impossible'
    else:
        for i in xrange(n):
            for j in xrange(n-1):
                print 0,
            if i < n - 1:
                print 1
            else:
                print 100
    print ''
    
