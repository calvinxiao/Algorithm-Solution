#Problem ID: 1245
#Submit Time: 2012-07-15 19:55:29
#Run Time: 890
#Run Memory: 588
#ZOJ User: calvinxiao

import sys

def getInt():
    return int(sys.stdin.readline())

def getList():
    return sys.stdin.readline().strip().split()

#M = [['' for i in xrange(101)] for j in xrange(101)]
CASE = 0
N = getInt()
while N != 0:
    length = 2 * N - 1
    CASE +=1
    ans = 0
    M = []
    
    for i in xrange(N):
        M.append(sys.stdin.readline())

    #dp, max height of the retangle
    dp = [[0 for i in xrange(length)] for j in xrange(N)]
    dp2 = [[0 for i in xrange(length)] for j in xrange(N)]
    for i in xrange(N):
        for j in xrange(i, length - i):
            if M[i][j] == '-':
                ans = 1
                dp[i][j] = 1
                dp2[i][j] = 1
                

    for i in xrange(0, N):
        for j in xrange(1, length - 1):
            if i > 0 and i % 2 == j % 2:
                if dp[i][j] > 0 and dp[i-1][j] > 0 and dp[i-1][j-1] > 0 and dp[i-1][j+1] > 0:
                    dp[i][j] = max(dp[i][j], min(dp[i-1][j-1], dp[i-1][j+1]) + 1)
                ans = max(ans, dp[i][j])
            ii = N - i - 1
            if ii < N - 1 and not ii % 2 == j % 2:
                if dp2[ii][j] > 0 and dp2[ii+1][j] > 0 and dp2[ii+1][j-1] > 0 and dp2[ii+1][j+1] > 0:
                    dp2[ii][j] = max(dp2[ii][j], min(dp2[ii+1][j-1], dp2[ii+1][j+1]) + 1)
                ans = max(ans, dp2[ii][j])
    
##    for i in xrange(1, N):
##        for j in xrange(i, length - i):
##            if M[i][j] == '-':
##                if i % 2 == j % 2 and M[i-1][j] == '-' and M[i-1][j-1] == '-' and M[i-1][j+1] == '-':
##                    dp[i][j] = max(dp[i][j], min(dp[i-1][j-1], dp[i-1][j+1]) + 1)
##                ans = max(ans, dp[i][j])
##                
##    for i in xrange(N - 3, -1, -1):
##        for j in xrange(i + 2, length - i - 2):
##            if M[i][j] == '-':
##                print j
##                if i % 2 == j % 2 and M[i+1][j] == '-' and M[i+1][j-1] == '-' and M[i+1][j+1] == '-':
##                    dp2[i][j] = max(dp2[i][j], min(dp2[i+1][j-1], dp2[i+1][j+1]) + 1)
##                ans = max(ans, dp2[i][j])
                
##    for i in xrange(0, N):
##        for j in xrange(0, length):
##            print dp2[i][j],
##        print ''

    if ans == 0:
        ans = 0
    elif ans == 1:
        ans = 1
    else:
        ans = ans ** 2
    print 'Triangle #%d' % CASE
    print 'The largest triangle area is %d.' % ans
    print ''

    N = getInt()

    
