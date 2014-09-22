#Problem ID: 1025
#Submit Time: 2012-07-01 20:04:23
#Run Time: 540
#Run Memory: 1176
#ZOJ User: calvinxiao

import sys

def getInt():
    return int(sys.stdin.readline())

def getList():
    return sys.stdin.readline().strip().split(' ')

CASES = getInt()
for CASE in xrange(CASES):
    ans = 0
    n = getInt()
    a = [ [0,0] for i in xrange(n)]
    used = [False for i in xrange(n)]
    line = getList()
    for i in xrange(0, 2 * n, 2):
        a[i/2][0] = int(line[i])
        a[i/2][1] = int(line[i+1])

    a.sort()
    nextI = 0
    for i in xrange(n):
        if not used[i]:
            used[i] = True
            ans += 1
            L = a[i][0]
            W = a[i][1]
            for j in xrange(i + 1, n):
                if not used[j]:
                    if a[j][0] >= L and a[j][1] >= W:
                        used[j] = True
                        L = a[j][0]
                        W = a[j][1]
                    else:
                        if nextI == i:
                            nextI = j
            i = nextI
                    
                    
    print ans
    #print a

    
