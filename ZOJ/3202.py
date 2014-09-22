#Problem ID: 3202
#Submit Time: 2012-09-13 16:21:32
#Run Time: 30
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

TC = getint()
for tc in xrange(TC):
    n = getint()
    a = [int(num) for num in getlist()]
    b = [[] for i in xrange(n)]
    for i in xrange(len(a)):
        b[i] = [i+1, a[i]]
    b.sort(key = lambda s:s[1], reverse = True)
    print b[0][0], b[1][1]
    
