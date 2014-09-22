#Problem ID: 1711
#Submit Time: 2013-03-09 16:51:28
#Run Time: 340
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

while 1:
    a = getints()
    if sum(a) == 0:
        break
    se = set([])
    t, n = a[0], a[1]
    a = [a[i] for i in xrange(2, n+2)]
    a.sort(reverse=True)
    for mask in xrange(1<<n):
        s = []
        tt = 0
        for i in xrange(n):
            if ((1<<i) & (mask)):
                tt += a[i]
        if tt == t:
            for i in xrange(n):
                if ((1<<i) & (mask)):
                    s.append(str(a[i]))
            se.add('+'.join(s))
    ans = len(se)
    print 'Sums of %d:' % t
    if not ans:
        print 'NONE'
    else:
        lst = list(se)
        lst.sort(reverse=True)
        for s in lst:
            print s
