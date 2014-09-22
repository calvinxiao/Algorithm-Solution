#Problem ID: 2740
#Submit Time: 2013-02-18 11:45:06
#Run Time: 130
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
    n, m = getints()
    if not n and not m:
        break
    f = range(n+1)
    ans = 1
    for i in xrange(m):
        good = True
        a, b = getints()
        if good:
            while f[b] != f[f[b]]: f[b] = f[f[b]]
            while f[a] != f[f[a]]: f[a] = f[f[a]]
            if f[a] != f[b]:
                ans += 1
                f[f[a]] = f[b]
            else:
                good = False
    if good and ans == n:
        print 'Yes'
    else:
        print 'No'
    getline()
           
