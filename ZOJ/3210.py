#Problem ID: 3210
#Submit Time: 2012-11-03 15:06:55
#Run Time: 30
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline().strip()

def getint():
    return int(getline())

def getints():
    return [int(num) for num in getline().split()]

#sys.stdin = open("0.in", "r")

T = getint()
for tc in xrange(T):
    n = getint()
    a = getints()
    b = getints()
    ans = 0
    #queue
    good = True
    for i in xrange(n):
        if a[i] != b[i]:
            good = False
            break
    if good:
        ans += 1

    #stack
    good = True
    for i in xrange(n):
        if a[i] != b[n - i - 1]:
            good = False
            break
    if good:
        ans += 2

    if ans == 0:
        print 'neither'
    elif ans == 1:
        print 'queue'
    elif ans == 2:
        print 'stack'
    else:
        print 'both'
    
