#Problem ID: 2330
#Submit Time: 2012-09-14 17:55:14
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys
from math import *

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

s = set([1])
L = [362880, 40320, 1, 2, 5040, 6, 720, 120, 24]

E = exp(1.0)
mini = 0.000001
while 1:
    line = getline()
    if not line:
        break
    n = float(line)
    if n > E:
        print -1
        continue
    t = log(n) / n
    left = E
    right = 44.0
    while left <= right:
        mid = (left + right) / 2
        x = log(mid) / mid
        if x < t:
            right = mid - mini
        elif x > t:
            left = mid + mini
        else:
            break
    print '%.5f' % mid
