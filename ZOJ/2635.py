#Problem ID: 2635
#Submit Time: 2012-09-10 17:45:24
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

TC = getint()
for tc in xrange(TC):
    line = getline().strip()
    key = []
    for i in xrange(len(line)):
        key.append([line[i], i])
    key.sort()
    #print key
    ci = getline().strip()
    n = len(ci)
    m = len(key)
    ansj = 0
    ans = ['' for i in xrange(n)]
    for i in xrange(m):
        jdx = key[i][1]
        idx = 0
        while 1:
            if idx * m + jdx < n:
                ans[idx * m + jdx] = ci[ansj]
                ansj += 1
                if ansj >= n:
                    break
            else:
                break
            idx += 1
        if ansj >= n:
            break
    print ''.join(ans).lower()
        
