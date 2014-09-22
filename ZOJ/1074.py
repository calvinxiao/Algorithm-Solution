#Problem ID: 1074
#Submit Time: 2012-07-01 23:04:43
#Run Time: 1860
#Run Memory: 9288
#ZOJ User: calvinxiao

import sys

def getInt():
    return int(sys.stdin.readline())

def getList():
    return sys.stdin.readline().strip().split()

ans = -100000000
n = getInt()
num =[[0 for i in xrange(n)] for j in xrange(n)]
dp = [[[0 for k in xrange(n+1)] for i in xrange(n)] for j in xrange(n)]
    
i = 0
j = 0

line = sys.stdin.readline().split()
while line:
    for k in xrange(len(line)):
        num[i%n][j%n] = int(line[k])
        dp[i%n][j%n][1] = int(line[k])
        ans = max(ans, int(line[k]))
        j += 1
        if j % n == 0:
            i += 1
    line = sys.stdin.readline().split()
    
#print num
for L in xrange(2, n+1):
    for i in xrange(n):
        for j in xrange(n - L + 1):
            dp[i][j][L] = dp[i][j][L-1] + num[i][j + L - 1]


for L in xrange(1, n+1):
    for j in xrange(n - L + 1):
        s = 0
        for i in xrange(n):
            s += dp[i][j][L]
            if s < 0:
                s = 0
            else:
                ans = max(ans, s)

print ans
            
