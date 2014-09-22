#Problem ID: 1915
#Submit Time: 2012-08-16 17:38:29
#Run Time: 40
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

cases = getint()
for case in xrange(cases):
    a = [float(num) for num in getlist()]
    total = 0.0
    for i in xrange(1, len(a)):
        total += a[i]
    avg = total / a[0]
    cnt = 0.0
    for i in xrange(1, len(a)):
        if a[i] > avg:
            cnt += 1.0
    print ('%.3f'%(cnt / a[0] * 100.0)) + '%'
    
