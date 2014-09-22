#Problem ID: 1350
#Submit Time: 2013-03-07 14:47:39
#Run Time: 30
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

def gao(n):
    a = [1 for i in xrange(n+1)]
    for i in xrange(1, n+1):
        for j in xrange(i, n+1, i):
            a[j] ^= 1
    ans = 0
    for i in xrange(1, n+1):
        if not a[i]:
            ans += 1
    #print a
    return ans

T = getint()
while T:
    T -= 1
    print gao(input())
    
