#Problem ID: 1216
#Submit Time: 2012-08-30 23:09:27
#Run Time: 140
#Run Memory: 2264
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()
dp = [0.0 for i in xrange(100000)]
for i in xrange(99999):
    dp[i + 1] = dp[i] + 0.5 / (i + 1)
tc = 0

print '# Cards  Overhang'
while 1:
    line = getline()
    if not line:
        break
    n = int(line)
    print '%5d     %4.3f' % (n, dp[n])
