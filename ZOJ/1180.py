#Problem ID: 1180
#Submit Time: 2012-09-16 00:56:07
#Run Time: 5790
#Run Memory: 4788
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

def D(t):
    tt = t
    while tt != 0:
        t += tt % 10
        tt /= 10
    return t

ans = [False for i in xrange(1000001)]

for i in xrange(1, 1000001):
    if not ans[i]:
        print i
        t = i
        while t <= 1000000:
            if ans[t]:
                break
            #print t
            ans[t] = True
            tt = t
            while tt != 0:
                t += tt % 10
                tt /= 10

    
