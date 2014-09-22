#Problem ID: 1797
#Submit Time: 2012-09-17 18:10:58
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

def gcd(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    if a == 0 or b == 0:
        return 0
    else:
        return a * b / gcd(a, b)
    
TC = getint()
for tc in xrange(TC):
    a = [int(num) for num in getlist()]
    n = a[0]

    if n == 0:
        ans = 0
    else:
        ans = a[1]
    for i in xrange(1, n + 1):
        ans = lcm(ans, a[i])
    print ans

    
