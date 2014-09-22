#Problem ID: 2972
#Submit Time: 2012-09-13 00:48:15
#Run Time: 210
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
    PRE = [10000000 for i in xrange(m + 1)]
    PRE[m] = 0
    for i in xrange(n):
        t1, t2, t3, f1, f2 = [int(num) for num in getlist()]
        NEXT = [10000000 for i in xrange(m + 1)]
        for j in xrange(m + 1):
            k = j - f1
            if k >= 0:
                NEXT[k] = min(NEXT[k], PRE[j] + t1)
            NEXT[j] = min(NEXT[j], PRE[j] + t2)
            k = j + f2
            if k > m:
                k = m
            NEXT[k] = min(NEXT[k], PRE[j] + t3)
        PRE = NEXT
    print min(PRE)
        

    
