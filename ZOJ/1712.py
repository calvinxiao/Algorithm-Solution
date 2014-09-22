#Problem ID: 1712
#Submit Time: 2013-03-09 15:26:20
#Run Time: 10
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
    n = input()
    if not n:
        break
    l = str(n)
    l = [int(c) for c in l]
    l.reverse()
    two = 1
    ans = 0
    for i in xrange(len(l)):
        two *= 2
        ans += l[i] * (two - 1)
    print ans
