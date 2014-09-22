#Problem ID: 2604
#Submit Time: 2013-09-28 11:36:02
#Run Time: 160
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

dp = [[0 for i in xrange(52)] for j in xrange(52)]
for j in xrange(52):
    dp[0][j] = 1

for i in xrange(1, 52):
    for j in xrange(1, 52):
        for k in xrange(1, i+1):
            dp[i][j] += dp[k-1][j-1] * dp[i-k][j]
tc = 0
while 1:
    n, k = map(int, raw_input().split())
    if not n and not k:
        break
    if tc:
        print ''
    tc += 1
    print 'Case %d: %d' % (tc, dp[n][k] - dp[n][k-1])
