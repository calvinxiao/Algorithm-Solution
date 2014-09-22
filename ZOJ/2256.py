#Problem ID: 2256
#Submit Time: 2012-08-15 14:27:42
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

a = [0 for i in xrange(17)]

def f(n):
    
    if n <= 4:
        return 100
    elif n <= 8:
        return 100 + (n - 4) * 20
    else:
        return 180 + (n - 8) * 24

def solve(n):
    if n <= 8:
        return f(n)
    else:
        cnt = n / 8
        if cnt == 1:
            return min(f(n), f(8) + f(n-8))
        elif cnt > 1:
            return (cnt - 1) * f(8) + solve(n - cnt * 8 + 8)

for i in xrange(1, 17):
    a[i] = solve(i)
    
while 1:
    n = getint()
    if not n:
        break
    ans = 0
    cnt = n / 16
    re = n % 16
    if cnt < 1:
        ans =  a[n]
    else:
        if re >= 8:
            ans = cnt * a[16] + a[re]
        else:
            ans = (cnt - 1) * a[16] + a[8] + a[8 + re]
    if ans % 10 == 0:
        print ans/10
    else:
        print '%d.%d' % (ans / 10, ans % 10)
    #print a
