#Problem ID: 2969
#Submit Time: 2012-09-13 00:10:17
#Run Time: 230
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
    n = getint()
    c = [int(num) for num in getlist()]
    if n == 0:
        print 0
    else:
        ans = []
        i = 0
        while n > 0:
            ans.append(c[i] * n)
            i += 1
            n -= 1
        print ' '.join([str(num) for num in ans])

    
