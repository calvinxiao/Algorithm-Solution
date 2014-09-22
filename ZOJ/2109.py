#Problem ID: 2109
#Submit Time: 2012-09-10 13:47:22
#Run Time: 680
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
    line = getline()
    if not line:
        break
    m, n = [int(num) for num in line.split()]
    if m == -1 and n == -1:
        break
        
    a = []
    for i in xrange(n):
        j, f = [int(num) for num in getlist()]
        if f != 0:
            ratio = 1.0 * j / f
        else:
            ratio = 1000000000
        a.append([ratio, j, f])
        
    a.sort(reverse = True)
    ans = 0.0
    for i in xrange(n):
        if m >= a[i][2]:
            ans += a[i][1]
            m -= a[i][2]
        else:
            ans += m * a[i][0]
            break
    print '%.3f' % ans
