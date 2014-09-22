#Problem ID: 2388
#Submit Time: 2012-08-26 01:31:55
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

TC = getint()
for tc in xrange(TC):
    n, m = [int(num) for num in getlist()]
    if n < m:
        print 'impossible'
    else:
        if (n + m) % 2 == 0:
            a = (n + m) / 2
            b = n - a
            print a, b
        else:
            print 'impossible'

    
