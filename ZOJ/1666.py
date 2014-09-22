#Problem ID: 1666
#Submit Time: 2012-08-27 17:05:50
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

def gcd(a, b):
    if b != 0:
        return gcd(b, a % b)
    else:
        return a

dp = [0 for i in xrange(300)]
dp[0] = 1
for i in xrange(1, 18):
    sq = i ** 2
    for j in xrange(sq, 300):
        dp[j] += dp[j - sq]
            
while 1:
    n = getint()
    if not n:
        break
    print dp[n]
