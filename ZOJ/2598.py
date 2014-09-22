#Problem ID: 2598
#Submit Time: 2012-09-29 10:18:05
#Run Time: 50
#Run Memory: 916
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

dp = [{} for i in xrange(1000)]

def f(a, b):
    #print a, b
    if b == 0 or b == 1:
        return 1
    elif b in dp[a]:
            return dp[a][b]
    else:
        if b % 2 == 1:
            dp[a][b] = f(a+1, b/2)
        else:
            dp[a][b] = f(a+1, b/2) + f(a+1, b/2-1)
    return dp[a][b]
    
while 1:
    num = getint()
    if num < 0:
        break
    print f(0, num)

    

    

