#Problem ID: 1251
#Submit Time: 2012-08-30 22:04:03
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
tc = 0
while 1:
    tc += 1
    n = getint()
    if not n:
        break
    a = [int(num) for num in getlist()]
    avg = sum(a) / n
    ans = 0
    for i in xrange(n):
        if a[i] > avg:
            ans += a[i] - avg
    print 'Set #%d\nThe minimum number of moves is %d.\n' % (tc, ans)
