#Problem ID: 1733
#Submit Time: 2012-08-13 00:20:56
#Run Time: 170
#Run Memory: 584
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    line = getline()
    if not line:
        break
    if len(line.split()) == 1:
        a = line
        b = getline()
    else:
        a, b = line.split()
    a = a.split()[0]
    b = b.split()[0]

    n = len(a)
    m = len(b)
    f = [[0 for j in xrange(m)] for i in xrange(n)]
    if a[0] == b[0]:
        f[0][0] = 1
    for i in xrange(1, n):
        if a[i] == b[0]:
            f[i][0] = 1
        else:
            f[i][0] = f[i-1][0]
    for i in xrange(1, m):
        if b[i] == a[0]:
            f[0][i] = 1
        else:
            f[0][i] = f[0][i-1]
    
    for i in xrange(1, n):
        for j in xrange(1, m):
            if a[i] == b[j]:
                f[i][j] = 1 + f[i-1][j-1]
            else:
                f[i][j] = max(f[i-1][j], f[i][j-1])
    print f[n-1][m-1]
