#Problem ID: 2947
#Submit Time: 2012-08-09 10:21:55
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

CASES = getint()

for CASE in xrange(CASES):
    n = getint()
    A = ''.join([num[0] for num in getlist()])
    m = getint()
    if n != m:
        print 'DIFFERENT'
        getline()
        continue
    B = ''.join([num[0] for num in getlist()])
    if A == B:
        print 'SAME'
    else:
        print 'DIFFERENT'

    
