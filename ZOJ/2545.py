#Problem ID: 2545
#Submit Time: 2013-05-05 20:22:59
#Run Time: 850
#Run Memory: 9860
#ZOJ User: calvinxiao


import sys

def getline():
    return sys.stdin.readline()

def getint():
    return input()

def getints():
	return map(int, raw_input().split())

def getlist():
    return raw_input().split()

#sys.stdin = open("0.in", "r")
from math import *

bit = 4
m = []
for year in xrange(1960, 2161, 10):
    m.append(bit)
    bit <<= 1
BIG = bit
fac = [0.0]
s = 0.0
for i in xrange(1, 1000000):
    s += log(i, 2)
    if s >= BIG:
        break
    fac.append(s)
#print len(fac)
n = len(fac)
while 1:
    year = getint()
    if not year:
        break
    year = (year - 1960) / 10
    l, r = 0, n-1
    ans = 0
    while l < r + 1:
        mid = l + r >> 1
        if fac[mid] < m[year]:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print ans
