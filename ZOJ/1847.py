#Problem ID: 1847
#Submit Time: 2013-04-14 21:23:48
#Run Time: 50
#Run Memory: 320
#ZOJ User: calvinxiao

import sys
import math

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getints():
        return [int(num) for num in getlist()]

def getlist():
    return sys.stdin.readline().strip().split()

#sys.stdin = open("0.in", "r")
while True:
    n = getint()
    if not n:
        break
    a = [0.0 for i in xrange(n)]
    for i in xrange(n):
        a[i] = float(getline())
    avg = 1.0 * sum(a) / n
    a1, a2 = 1.0 * int(avg * 100), 1.0 * int(avg * 100)
    a1 /= 100.0
    if a2 < avg * 100:
        a2 += 1
    a2 /= 100.0
    ans1, ans2 = 0.0, 0.0
    for i in xrange(n):
        if a[i] < avg:
            ans1 += a1 - a[i]
        else:
            ans2 += a[i] - a2

    #print avg, ans
    if ans1 > ans2:
        print '$%.2f' % ans1
    else:
        print '$%.2f' % ans2

    
