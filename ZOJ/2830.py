#Problem ID: 2830
#Submit Time: 2012-08-15 18:00:42
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

def doit(n):
    if n == 1:
        return 0
    ans = 0
    while n != 0:
        if n <= 3:
            ans += 1
            return ans
        t = n / 3
        ans += t
        t += n % 3
        n = t
    return ans

while 1:
    n = getint()
    if not n:
        break

    ans = (n-1) / 2
    if (n-1) % 2 == 1:
        ans += 1
    print ans
    #print doit(n)

