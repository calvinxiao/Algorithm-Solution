#Problem ID: 2108
#Submit Time: 2012-09-10 13:25:47
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
    a = [int(num) for num in getlist()]
    if a[0] == 0:
        break
    a[0] = 0
    ans = 0
    floor = 0
    for i in xrange(1, len(a)):
        floor = a[i] - a[i-1]
        if floor > 0:
            ans += floor * 6 + 5
        else:
            ans += -floor * 4 + 5
    print ans
    
