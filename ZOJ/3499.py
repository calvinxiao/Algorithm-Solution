#Problem ID: 3499
#Submit Time: 2012-08-20 12:50:54
#Run Time: 60
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
for i in xrange(TC):
    n = getint()
    if n % 2 == 1:
        a = [float(num) for num in getlist()]
        a.sort()
        print '%.3f' % (a[n / 2])
    else:
        a = [float(num) for num in getlist()]
        a.sort()
        print '%.3f' % ((a[n/2] + a[n/2 - 1]) / 2.0)

    
