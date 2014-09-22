#Problem ID: 1269
#Submit Time: 2013-05-09 18:03:01
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    n = getint()
    if n == -1:
        break
    found = False
    for ans in xrange(10, 1, -1):
        if found:
            break
        nn = n
        bad = False
        for i in xrange(ans):
            if nn % ans == 1:
                nn -= nn/ans + 1
            else:
                bad = True
                break
        if nn % ans != 0:
            bad = True
        if bad:
            continue
        #print nn
        print '%d coconuts, %d people and 1 monkey' % (n, ans)
        found = True
        break
    if not found:
        print '%d coconuts, no solution' % n
