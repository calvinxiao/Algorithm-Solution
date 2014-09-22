#Problem ID: 2416
#Submit Time: 2012-08-16 15:46:34
#Run Time: 40
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

def count(a, b):
    ans = 0
    for i in xrange(4):
        I, A = [a[i], b[i]]
        if I > A:
            I, A = A, I
        ans += min(A - I, I + 9 - A)
    return ans

def tostr(a):
    return ''.join([str(num) for num in a])

def todo(a, b):
    d = {}
    d[tostr(a)] = 0
    ans = 100000
    ans = min(ans, count(a, b))
    q = [a]
    while len(q):
        newq = []
        for k in q:
            for i in xrange(3):
                newk = [num for num in k]
                newk[i], newk[i+1] = newk[i+1], newk[i]
                if not tostr(newk) in d:
                    d[tostr(newk)] = d[tostr(k)] + 1
                    ans = min(ans, d[tostr(newk)] + count(newk, b))
                    newq.append(newk)
        q = [num for num in newq]
    return ans

cases = getint()
for case in xrange(cases):
    if case != 0:
        getline()
    line = getline()
    a = [int(num) for num in line[0:4]]
    line = getline()
    b = [int(num) for num in line[0:4]]
    #print a
    #print b
    print todo(a, b)
    
        

