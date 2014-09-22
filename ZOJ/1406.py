#Problem ID: 1406
#Submit Time: 2012-09-19 02:46:25
#Run Time: 80
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()
    
while 1:
    n = getint()
    if not n:
        break
    g = [[0 for i in xrange(n)] for j in xrange(n)]
    ans = 0
    for i in xrange(n-1):
        l = getlist()
        s = ord(l[0]) - ord('A')
        cnt = int(l[1])
        idx = 2
        for j in xrange(cnt):
            e = ord(l[idx]) - ord('A')
            cost = int(l[idx+1])
            g[s][e] = cost
            g[e][s] = cost
            idx += 2
    f = range(n)
    #print g
    cnt = 1
    while cnt < n:
        mini = 0
        minj = 0
        miniCost = 100000000
        for i in xrange(n):
            for j in xrange(i + 1, n):
                if i != j:
                    while f[i] != f[f[i]]:
                        f[i] = f[f[i]]
                    while f[j] != f[f[j]]:
                        f[j] = f[f[j]]
                    if f[i] != f[j] and g[i][j] != 0 and g[i][j] < miniCost:
                        mini, minj, miniCost = i, j, g[i][j]
        cnt += 1
        ans += miniCost
        f[f[mini]] = f[minj]
    print ans
                    




    
