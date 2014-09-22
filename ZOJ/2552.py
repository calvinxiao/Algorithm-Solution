#Problem ID: 2552
#Submit Time: 2013-08-14 22:47:50
#Run Time: 3800
#Run Memory: 320
#ZOJ User: calvinxiao


import sys

def getline():
    return sys.stdin.readline()

def getint():
    return input()

def getints():
	return map(int, raw_input().split())

def getlist():
    return raw_input().split()

#sys.stdin = open("0.in", "r")
tc = 0
while 1:
    nk = getints()
    if nk[0] == 0:
        break
    n, k = nk[0], nk[1]
    k = k * n * (n - 1) / 2
    if tc > 0:
        print ''
    tc += 1
    w, l = [0 for i in xrange(n+1)], [0 for i in xrange(n+1)]
    for kk in xrange(k):
        L = getline().split()
        a, b = int(L[0]), int(L[2])
        ca, cb = L[1][0], L[3][0]
        if ca == 'r':
            if cb == 'p':
                l[a] += 1
                w[b] += 1
            elif cb == 's':
                w[a] += 1
                l[b] += 1
        if ca == 'p':
            if cb == 's':
                l[a] += 1
                w[b] += 1
            elif cb == 'r':
                w[a] += 1
                l[b] += 1
        if ca == 's':
            if cb == 'r':
                l[a] += 1
                w[b] += 1
            elif cb == 'p':
                w[a] += 1
                l[b] += 1
    for i in xrange(1, n+1):
        if w[i] + l[i] == 0:
            print '-'
            continue
        print '%.3f' % (1.0*w[i]/(w[i] + l[i]))
