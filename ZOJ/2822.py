#Problem ID: 2822
#Submit Time: 2013-03-04 22:28:19
#Run Time: 1480
#Run Memory: 452
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

maxn, maxk = 1122, 15
isprime = [1 for i in xrange(maxn)]

isprime[0], isprime[1] = 0, 0
for i in xrange(maxn):
    if isprime[i]:
        for j in xrange(i+i, maxn, i):
            isprime[j] = 0
p = [i for i in xrange(maxn) if isprime[i]]

lp = len(p)

dp = [[0 for j in xrange(maxk)] for i in xrange(maxn)]

dp[0][0] = 1

for pi in p:
    for j in xrange(14, 0, -1):
        for i in xrange(maxn-1, pi-1, -1):
            dp[i][j] += dp[i-pi][j-1]
            
while 1:
    n, k = getints()
    if not n and not k:
        break
    print dp[n][k]
