#Problem ID: 2782
#Submit Time: 2013-02-18 14:37:48
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

tc = getint()
while tc:
    tc -= 1
    n, m = getints()
    s = getlist()
    t = ['' for i in xrange(n)]
    v = [0 for i in xrange(n)]
    for i in xrange(m):
        a, b = getints()
        a, b = a-1, b-1
        t[b] = s[a]
        v[a] = 1
    #print s
    #print t
    #print v
    i = 0
    for j in xrange(n):
        if t[j] == '':
            while v[i]:
                i += 1
            t[j] = s[i]
            i += 1
    print ' '.join(t)
