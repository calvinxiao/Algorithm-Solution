#Problem ID: 2424
#Submit Time: 2012-09-17 14:59:25
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

f = [0 for i in xrange(201)]
f[0] = 1
for n in xrange(2, 201, 2):
    for i in xrange(0, n, 2):
        f[n] += f[i] * f[n - i - 2]
while 1:
    n = getint()
    if n == -1:
        break
    print f[n + n]

    
