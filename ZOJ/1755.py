#Problem ID: 1755
#Submit Time: 2013-03-09 15:18:38
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
    if n == -1:
        break
    ans = []
    for i in xrange(n):
        l = getline().strip().split()
        ans.append([int(l[0]) * int(l[1]) * int(l[2]), l[3]])
    ans.sort()
    print '%s took clay from %s.' % (ans[n-1][1], ans[0][1])
