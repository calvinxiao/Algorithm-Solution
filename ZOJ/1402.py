#Problem ID: 1402
#Submit Time: 2012-09-19 01:18:48
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
    if not a[0]:
        break
    s = sum(a) - a[0]
    if s % 2 == 1:
        print 'No equal partitioning.'
        continue
    
    ans = 0
    temp = 0
    for i in xrange(1, a[0] + 1):
        temp += a[i]
        if temp == s / 2:
            ans = i
            break
    if temp == s / 2:
        print 'Sam stops at position %d and Ella stops at position %d.' % (ans, ans+1)
    else:
        print 'No equal partitioning.'



    
