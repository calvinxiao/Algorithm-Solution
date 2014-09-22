#Problem ID: 2001
#Submit Time: 2012-08-27 11:07:24
#Run Time: 180
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

TC = getint()
for tc in xrange(TC):
    a = getlist()
    #print a
    ans = int(a[0][::-1]) + int(a[1][::-1])
    ans = int(str(ans)[::-1])
    while ans % 10 ==0:
        ans /= 10
    print ans
    
