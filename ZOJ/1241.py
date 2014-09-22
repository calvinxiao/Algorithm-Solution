#Problem ID: 1241
#Submit Time: 2012-08-30 21:13:46
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

tc = 0
while 1:
    tc += 1
    a, b, c = [int(num) for num in getlist()]
    ans = 0.0
    if a == 0 and b == 0 and c == 0:
        break

    print 'Triangle #%d' % tc
    
    if c == -1:
        ans = pow(a * a + b * b, 0.5)
        print 'c = %.3f' % ans
    else:
        if a != -1:
            if c <= a:
                ans = 0.0
            else:
                ans = pow(c * c - a * a, 0.5)
                print 'b = %.3f' % ans
        elif b != -1:
            if c <= b:
                ans = 0.0
            else:
                ans = pow(c * c - b * b, 0.5)
                print 'a = %.3f' % ans
    
    if ans == 0.0:
        print 'Impossible.'
    print '' 
