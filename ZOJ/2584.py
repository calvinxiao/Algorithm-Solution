#Problem ID: 2584
#Submit Time: 2012-09-20 04:31:09
#Run Time: 370
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

a = [[0 for i in xrange(4)] for j in xrange(1001)]
a[1][1] = 1
c = 1
for i in xrange(2, 1001):
    a[i][0] = a[i-1][1]
    a[i][1] = a[i-1][0] + c
    a[i][2] = a[i-1][3] + c
    a[i][3] = a[i-1][2]
    c *= 2
while 1:
    line = getline()
    if not line:
        break
    n = int(line)
    print a[n][0]

    
