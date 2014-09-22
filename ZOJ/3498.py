#Problem ID: 3498
#Submit Time: 2012-08-20 15:26:06
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

def f(n):
    if n == 1:
        return 1
    else:
        return 1 + f(n/2)
TC = getint()
for i in xrange(TC):
    n = getint()
    print f(n)

    
