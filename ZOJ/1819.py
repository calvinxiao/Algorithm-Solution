#Problem ID: 1819
#Submit Time: 2012-10-05 22:37:01
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline().strip()

def getint():
    return int(getline())

def getints():
    return [int(num) for num in getline().split()]

dp = [[0 for i in xrange(51)] for j in xrange(51)]

for i in xrange(51):
    dp[i][1] = 1
    dp[i][i] = 1

for n in xrange(3, 51):
    for k in xrange(2, n):
        dp[n][k] += dp[n-1][k-1] + dp[n-1][k] * k

while 1:
    n = getint()
    if not n:
        break
    else:
        print '%d %d' % (n, sum(dp[n]) )

      
      
      
