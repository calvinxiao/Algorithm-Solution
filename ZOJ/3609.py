#Problem ID: 3609
#Submit Time: 2012-08-27 13:04:47
#Run Time: 290
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

def gcd(a, b):
    if b != 0:
        return gcd(b, a % b)
    else:
        return a
TC = getint()
for tc in xrange(TC):
    a, m = [int(num) for num in getlist()]
    a %= m
    if m == 1:
        print 1
    elif gcd(a, m) != 1:
        print 'Not Exist'
    else:
        for i in xrange(1, 10000):
            if a * i % m == 1:
                print i
                break
    
