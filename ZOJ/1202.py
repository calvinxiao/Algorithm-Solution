#Problem ID: 1202
#Submit Time: 2012-09-03 13:47:49
#Run Time: 20
#Run Memory: 452
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

dp = [[-1 for i in xrange(155)] for j in xrange(155)]
def C(n, k):
    if n == k:
        return 1
    elif k == 1:
        return n
    else:
        if dp[n][k] != -1:
            return dp[n][k]
        dp[n][k] = C(n-1, k) + C(n-1, k-1)
        return dp[n][k]

while 1:
    line = getline()
    if not line:
        break
    n = int(line)
    p = [0 for i in xrange(15)]
    ans = 1
    a = [int(num) for num in getlist()]
    for i in xrange(n):
        p[a[i]] += 1
    s = sum(a)
    for i in xrange(n):
        ans *= C(s, a[i])
        s -= a[i]
    for i in xrange(15):
        if p[i] > 1:
            for j in xrange(2, p[i] + 1):
                ans /= j
    print ans
    
