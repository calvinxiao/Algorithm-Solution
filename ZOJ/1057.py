#Problem ID: 1057
#Submit Time: 2013-03-14 23:09:26
#Run Time: 10
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

def score(c, d):
    #c < d
    if c == 1 and d == 2:
        return 6
    elif c + 1 == d:
        return c + d
    elif c + 1 < d:
        return -d
    return 0

while 1:
    n = getint()
    if not n:
        break
    a = getints()
    b = getints()
    A = 0
    B = 0
    for i in xrange(n):
        if a[i] < b[i]:
            add = score(a[i], b[i])
            if add > 0:
                A += add
            else:
                B -= add
        else:
            add = score(b[i], a[i])
            if add > 0:
                B += add
            else:
                A -= add
        #print a[i], b[i], A, B
    if tc:
        print ''
    tc += 1
    print 'A has %d points. B has %d points.' % (A, B)
