#Problem ID: 2104
#Submit Time: 2012-09-10 12:57:46
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
    if not n:
        break
    d = {}
    ans = 0
    ansS = ''
    for i in xrange(n):
        s = getline().strip()
        if s not in d:
            d[s] = 1
        if d[s] > ans:
            ans = d[s]
            ansS = s
    print s
    
