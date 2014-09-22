#Problem ID: 2679
#Submit Time: 2012-08-30 18:02:14
#Run Time: 920
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

def isprime(n):
    sn = pow(n, 0.5)
    for i in xrange(2,int(sn) + 1):
        if n % i == 0:
            return False
    return True

TC = getint()
for tc in xrange(TC):
    n = getint()
    x, y, z = [int(num) for num in getlist()]
    xyz = z * 10 + y * 100 + x * 1000
    flag = False
    for i in xrange(9, 0, -1):
        if not flag:
            for j in xrange(9, -1, -1):
                temp = i * 10000 + xyz + j
                if temp % n == 0:
                    print i, j, temp / n
                    flag = True
                    break
    if not flag:
        print 0
    
