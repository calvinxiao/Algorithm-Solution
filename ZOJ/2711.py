#Problem ID: 2711
#Submit Time: 2012-08-07 17:41:27
#Run Time: 240
#Run Memory: 3044
#ZOJ User: calvinxiao

import sys

def getLine():
    return sys.stdin.readline()

def getInt():
    return int(sys.stdin.readline())

def getList():
    return sys.stdin.readline().strip().split()

N = 0

def rec(a, b, c):
    if a < 0 or b < 0 or c < 0:
        return 0
    global N
    global dp
    if dp[a][b][c] != -1:
        return dp[a][b][c]
    dp[a][b][c] = 0
    if a > b:
        dp[a][b][c] += rec(a-1, b, c)
    if b > c:
        dp[a][b][c] += rec(a, b-1, c)
    dp[a][b][c] += rec(a, b, c-1)
    return dp[a][b][c]

line = getLine()
N = 61
ans = []
dp = [[[0 for k in xrange(N+1)] for i in xrange(N+1)] for j in xrange(N+1)]
dp[0][0][0] = 1
    #print rec(N, N, N)
for a in xrange(N+1):
    for b in xrange(a + 1):
        for c in xrange(b + 1):
            if a > b:
                dp[a][b][c] += dp[a-1][b][c]
            if b > c:
                dp[a][b][c] += dp[a][b-1][c]
            if c > 0:
                dp[a][b][c] += dp[a][b][c-1]

while line:
    N = int(line)
    getLine()
    print dp[N][N][N]          
    print ''
    line = getLine()
    
