#Problem ID: 1814
#Submit Time: 2012-09-06 17:32:07
#Run Time: 50
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

def solve(a, b):
    n = b - a
    step = 1
    ans = 0
    while n >= step:
        if n >= step * 2:
            n -= step * 2
            step += 1
            ans += 2
        else:
            n -= step
            step += 1
            ans += 1
    #now we have n steps left and would like use the minimun steps to repeat it
    #sounds like a currency problem
    if n != 0:
        ans += 1
    
    return ans

while 1:
    n = getint()
    if not n:
        break
    a = [0 for i in xrange(n)]
    for i in xrange(n):
        a[i] = getint()
    cnt = 0
    while 1:
        same = True
        for i in xrange(1, n):
            if a[i] != a[i-1]:
                same = False
                break
        if same:
            break

        cnt += 1
        temp = a[n-1] / 2
        for i in xrange(n):
            temp, a[i] = a[i] / 2, a[i] / 2 + temp
            if a[i] % 2 == 1:
                a[i] += 1
        
    print cnt, a[0]
