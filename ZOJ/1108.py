#Problem ID: 1108
#Submit Time: 2012-07-02 21:13:19
#Run Time: 620
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def RL():
    return sys.stdin.readline()

def getInt():
    return int(sys.stdin.readline())

def getList():
    return sys.stdin.readline().strip().split()

a = []
idx = 1
while 1:
    line = RL()
    if not line:
        break
    i, j = [int(L) for L in line.split(' ')]
    a.append([i, j, idx])
    idx += 1
a.sort(key = lambda b:b[1], reverse = True)
a.sort(key = lambda b:b[0])
#print a
ans = []
M = 0
n = len(a)
dp = [1 for i in xrange(n)]
for i in xrange(n):
    for j in xrange(i+1, n):
        if a[j][0] > a[i][0] and a[j][1] < a[i][1]:
            dp[j] = max(dp[j], dp[i] + 1)
            M = max(M, dp[j])
#print dp
print M
W = 10000000
S = -1
for i in xrange(-1, -n - 1, -1):
    if dp[i] == M and a[i][0] < W and a[i][1] > S:
        W = a[i][0]
        S = a[i][1]
        ans.append(a[i][2])
        M -= 1
ans.reverse()
#print ans
for i in xrange(len(ans)):
    print ans[i]

