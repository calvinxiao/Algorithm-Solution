#Problem ID: 2326
#Submit Time: 2013-02-18 12:24:17
#Run Time: 20
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

L = float(getline())
n = getint()
d = {}
idx = 0
for i in xrange(n):
    d[raw_input()] = idx
    idx += 1
f = range(n)
e = []

m = getint()
for i in xrange(m):
    a, b, c = getlist()
    e.append([float(c), d[a], d[b]])
e.sort()

ans = 0.0
for i in xrange(m):
    a, b = e[i][1:3]
    while f[a] != f[f[a]]: f[a] = f[f[a]]
    while f[b] != f[f[b]]: f[b] = f[f[b]]
    if f[a] != f[b]:
        ans += e[i][0]
        f[f[a]] = f[b]

if ans - L > 1e-6:
    print 'Not enough cable'
else:
    print 'Need %.1f miles of cable' % ans

           
