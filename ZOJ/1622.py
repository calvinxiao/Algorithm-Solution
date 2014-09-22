#Problem ID: 1622
#Submit Time: 2012-08-27 16:46:22
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
    if b != 0:
        return gcd(b, a % b)
    else:
        return a

while 1:
    line = getline()
    if not line:
        break
    c = [int(num) for num in line.split()]
    a = 1
    b = 0
    cnta = 0
    cntb = 0
    for i in xrange(1, c[0] + 1):
        if c[i] != a:
            cnta += 1
        if c[i] != b:
            cntb += 1
        a = (a + 1) % 2
        b = (b + 1) % 2
    print min(cnta, cntb)

    
