#Problem ID: 2321
#Submit Time: 2012-09-14 14:33:59
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

s = ['Wide Receiver','Lineman','Quarterback']
SP = [4.5,6.0,5.0]
WE = [150.0,300.0,200.0]
ST = [200.0,500.0,300.0]
while 1:
    sp, we, st = [float(num) for num in getlist()]
    if not sp and not we and not st:
        break
    ans = []
    for i in xrange(3):
        if sp <= SP[i] and we >= WE[i] and st >= ST[i]:
            ans.append(s[i])
    if len(ans):
        print ' '.join(ans)
    else:
        print 'No positions'

