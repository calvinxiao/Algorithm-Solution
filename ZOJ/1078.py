#Problem ID: 1078
#Submit Time: 2012-08-09 14:32:05
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

def doit(n):
    ans = []
    for d in xrange(2, 17):
        m = n
        num = []
        while m:
            num.append(m % d)
            m /= d
        
        i = 0
        j = len(num) - 1
        flag = True
        while i <= j:
            if num[i] != num[j]:
                flag = False
                break
            i += 1
            j -= 1
        if flag:
            ans.append(d)
    return ans
        
N = getint()
while N:
    ANS = doit(N)
    if len(ANS) > 0:
        print 'Number %d is palindrom in basis' % N,
        for i in xrange(len(ANS)):
            if i != len(ANS)-1:
                print ANS[i],
            else:
                print ANS[i]
    else:
        print 'Number %d is not a palindrom' % N
    
    N = getint()
    

    
