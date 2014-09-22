#Problem ID: 1874
#Submit Time: 2012-09-06 16:17:50
#Run Time: 0
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
    n, m = [int(num) for num in getlist()]
    if n == 0 and m == 0:
        break
    ten = 10
    ans = 0
    while ten <= 10000000000:
        if n % ten + m % ten >= ten:
            ans += 1
        ten *= 10
    if ans > 1:
        print '%d carry operations.' % ans
    elif ans == 1:
        print '%d carry operation.' % ans
    else:
        print 'No carry operation.'
    
