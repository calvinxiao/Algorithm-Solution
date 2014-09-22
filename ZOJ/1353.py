#Problem ID: 1353
#Submit Time: 2012-07-19 01:15:29
#Run Time: 580
#Run Memory: 584
#ZOJ User: calvinxiao

import sys

def getInt():
    return int(sys.stdin.readline())

def getList():
    return sys.stdin.readline().strip().split()

#judge input has max number 231...
MAX = 232
dp = [[-1 for j in xrange(MAX)] for i in xrange(MAX)]

def rec(left, i):
    global dp
    ret = 0
    if dp[left][i] != -1:
        return dp[left][i]
    elif i == 1:
        dp[left][i] = 1
        return 1
    elif left == 0:
        dp[left][i] = 1
        return 1
    for j in xrange(1, i + 1):
        if left - j >= 0:
            ret += rec(left - j, j)
    dp[left][i] = ret
    return ret

m = 0
N = getInt()
while N != 0:
    m = max(m, N)
    ans = 0
    if N % 2 == 1:
        for i in xrange(1, N + 1, 2):
            left = (N - i)/2
            ans += rec(left, i)
    else:
        for i in xrange(2, N + 1, 2):
            left = (N - i)/2
            ans += rec(left, i)
        for i in xrange(1, N/2 + 1):
            left = (N - 2 * i)/2
            ans += rec(left, i)
    print N, ans
    N = getInt()
