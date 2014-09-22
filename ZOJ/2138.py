#Problem ID: 2138
#Submit Time: 2012-10-25 14:16:48
#Run Time: 50
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getints():
    return [int(num) for num in getlist()]

def getlist():
    return sys.stdin.readline().strip().split()

#sys.stdin = open("a.txt", "r")

TC = getint()
for tc in xrange(TC):
    getline()
    if tc:
        print ''
    n, p = getints()
    ans = [0 for i in xrange(p)]

    for i in xrange(n):
        a = getints()
        tmp = min(a)
        tmp2 = max(a)
        for j in xrange(p):
            #print a[j], tmp
            if a[j] == tmp:
                ans[j] += 1
            if a[j] == tmp2:
                ans[j] -= 1000
    #print ans
    cnt = (n + 1) / 2
    output = []
    for i in xrange(p):
        if ans[i] >= cnt:
            output.append(i+1)
    if len(output):
        print ' '.join(str(num) for num in output)
    else:
        print 0
