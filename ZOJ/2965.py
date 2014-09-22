#Problem ID: 2965
#Submit Time: 2012-08-10 14:58:24
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

if 0:
    p = [0 for i in xrange(999)]
    for i in xrange(1, 999):
        a = i
        if i % 7 == 0:
            p[i] = 1
        else:
            while a:
                if a % 10 == 7:
                    p[i] = 1
                    break
                a /= 10

    ans = [0 for i in xrange(101)]
    for i in xrange(1, 999):
        cnt = 0
        for j in xrange(i, 999):
            if p[j] == 1:
                cnt += 1
                if ans[cnt] == 0:
                    ans[cnt] = i
            else:
                break

    print ans

ans = [0, 7, 27, 70, 70, 70, 70, 70, 70, 70, 70, 270, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700, 700]

n = getint()
while n:
    n -= 1
    print ans[getint()]
#for i in xrange(1, 101):
#    print i, ans[i]
