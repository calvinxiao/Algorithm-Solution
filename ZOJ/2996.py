#Problem ID: 2996
#Submit Time: 2012-10-08 12:24:38
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getints():
    return [int(num) for num in getlist()]

def getlist():
    return sys.stdin.readline().strip().split()

def f(n):
    cnt = 0
    n >>= 1
    while n:
        cnt += n
        n >>= 1
    return cnt
while 1:
    line = getline()
    if not line:
        break
    n, i = [int(num) for num in line.split()]
    if f(n) > f(i) + f(n-i):
        print 0
    else:
        print 1

    
