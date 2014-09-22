#Problem ID: 1602
#Submit Time: 2012-05-31 00:22:46
#Run Time: 300
#Run Memory: 320
#ZOJ User: calvinxiao

from sys import stdin

while True:
    line = stdin.readline()
    if not line:
        break
    
    n = int(line)
    ans = 0

    a = []
    dp = [[0 for i in xrange(n+1)] for j in xrange(n+1)]
    temp = stdin.readline().split(' ')
    for i in xrange(n):
        a.append(int(temp[i]))

    for i in xrange(1, n-1):
            dp[i-1][i+1] = a[i-1] * a[i] * a[i+1] 

    for len in xrange(4, n + 1):
        for i in xrange(0, n - len +1):
            k = i + len - 1
            if not dp[i][k] == 0:
                continue
            else:
                m = 10000000
                for j in xrange(i + 1, k):
                    m = min(m, dp[i][j] + dp[j][k] + a[i]*a[j]*a[k])
                dp[i][k] = m
    print dp[0][n-1]
    '''
    for i in xrange(2, n):
        for j in xrange(0, i-1):
            if dp[j][i] != 0:
                continue
            m = 100000000
            for k in xrange(j+1, i):
                m = min(m, a[i]*a[k]*a[j] + dp[k][i] + dp[j][k])
            dp[j][i] = m
    '''   
    #print dp[0][n-1]
    '''
    a = []
    m = [[0 for i in xrange(2)] for j in xrange(n)]
    vis = [False for i in xrange(n)]

    temp = stdin.readline().split(' ')
    for i in xrange(n):
        a.append(int(temp[i]))

    for i in xrange(1, n-1):
        m[i][0] = i-1
        m[i][1] = i+1
    
    #print m
    while n > 2:
        n -= 1
        maxA = 0
        minV = 1000001
        index = 0

        for i in xrange(1, N-1):
            if not vis[i]:
                if maxA < a[i]:
                    maxA = a[i]
        
        for i in xrange(1, N-1):
            if not vis[i] and a[i] == maxA:
                if minV > (a[i] * a[m[i][0]] * a[m[i][1]]):
                    minV = (a[i] * a[m[i][0]] * a[m[i][1]])
                    index = i
                    
        ans += minV
        #print index, m[index][0], a[index], m[index][1], minV
        vis[index] = True
        #print m[1][1], index
        for i in xrange(1, N-1):
            #print i, vis[i], m[i][1], index
            if not vis[i]:
                if m[i][0] == index:
                    m[i][0] = m[index][0]
                elif m[i][1] == index:
                    m[i][1] = m[index][1]
        #print m
        print ans

    '''
    

