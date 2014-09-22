#Problem ID: 2176
#Submit Time: 2012-09-10 13:32:46
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
    pre = 0
    ans = 0
    for i in xrange(n):
        s, t = [int(num) for num in getlist()]
        ans += s * (t - pre)
        pre = t
    ans
    print '%d miles' % ans
    
