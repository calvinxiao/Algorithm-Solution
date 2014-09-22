#Problem ID: 1619
#Submit Time: 2013-11-01 02:58:56
#Run Time: 30
#Run Memory: 140
#ZOJ User: calvinxiao

import sys

N = 100
f = [0 for i in xrange(N)]
g = [0 for i in xrange(N)]
f[0] = 1
for i in xrange(1, N):
    f[i] = i * f[i-1]
g[0], g[1] = 1, 0
for i in xrange(2, N):
    g[i] = (i - 1) * (g[i-1] + g[i-2])

while 1:
    line = sys.stdin.readline()
    if not line:
        break
    n, m = map(int, line.split())
    ans = 1.0 *  g[n-m] / (f[m] * f[n-m])
    print '%.8f' % ans
