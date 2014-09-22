#Problem ID: 1813
#Submit Time: 2012-09-06 01:13:58
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
    lst = getlist()
    if lst[1] == '0':
        break
    d = float(lst[0])
    r = float(lst[1])
    t = float(lst[2])

    D = d * 3.141592653 * r / 5280.0 / 12.0
    V = D / t * 3600.0
    print 'Trip #%d: %.2f %.2f' % (tc, D, V)
    

    
