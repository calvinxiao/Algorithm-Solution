#Problem ID: 1715
#Submit Time: 2013-03-09 16:36:14
#Run Time: 100
#Run Memory: 320
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

while 1:
    n, q = getints()
    if n+q == 0:
        break
    d = [0 for i in xrange(111)]
    ansI, ansC = 0, 0
    for i in xrange(n):
        a = getints()
        for j in xrange(1, a[0] + 1):
            d[a[j]] += 1
    for i in xrange(1, 111):
        if ansC < d[i]:
            ansC = d[i]
            ansI = i
    if ansC < q:
        ansI = 0
    print ansI
