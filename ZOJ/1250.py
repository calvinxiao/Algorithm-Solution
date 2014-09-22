#Problem ID: 1250
#Submit Time: 2012-07-15 23:22:15
#Run Time: 330
#Run Memory: 452
#ZOJ User: calvinxiao

import sys

def getInt():
    return int(sys.stdin.readline())

def getList():
    return sys.stdin.readline().strip().split()

N, K = [int(L) for L in getList()]
CASE = 0
MAX = 1000000007
while N != 0 and K != 0:
    CASE += 1
    dp = [[MAX for j in xrange(K)] for i in xrange(N)]
    c = [[[] for i in xrange(N)] for j in xrange(N)]
    for i in xrange(N):
        for j in xrange(N):
            if i != j:
                lst = getList()
                cnt = int(lst[0])
                for k in xrange(1, cnt + 1):
                    c[i][j].append(int(lst[k]))
                #print len(c[i][j])
    
    for i in xrange(1, N):
        if c[0][i][0] != 0:
            dp[i][0] = c[0][i][0]

    for k in xrange(1, K):
        for i in xrange(N):
            if dp[i][k-1] != MAX:
                for j in xrange(N):
                    if i != j and c[i][j][k%len(c[i][j])] != 0:
                        dp[j][k] = min(dp[j][k], dp[i][k-1] + c[i][j][k%len(c[i][j])])
                        #print i, j, dp[j][k]
    
    print 'Scenario #%d' % CASE
    if dp[N-1][K-1] != MAX:
        print 'The best flight costs %d.' % dp[N-1][K-1]
    else:
        print 'No flight possible.'
    print ''

    N, K = [int(L) for L in getList()]
    
