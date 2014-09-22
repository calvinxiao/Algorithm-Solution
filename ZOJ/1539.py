#Problem ID: 1539
#Submit Time: 2012-08-18 21:58:23
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

dp = {}
def f(n):
    if n < 3:
        return 0
    elif n == 3:
        return 1
    if not n in dp:
        if n % 2 == 0:
            r = 2 * f(n/2)
            dp[n] = r
            return r
        else:
            r = f(n/2) + f(n/2+1)
            dp[n] = r
            return r
    else:
        return dp[n]

while 1:
    line = getline()
    if not line:
        break
    print f(int(line))
    
