#Problem ID: 2374
#Submit Time: 2012-07-25 15:35:36
#Run Time: 290
#Run Memory: 1132
#ZOJ User: calvinxiao

import sys
from collections import deque

def getInt():
    return int(sys.stdin.readline())

def getList():
    return sys.stdin.readline().strip().split()



n = getInt()
while n:
    root = {}
    p = [0 for i in xrange(n + 1)]
    a = [0 for i in xrange(n + 1)]
    v = [1 for i in xrange(n + 1)]
    c = [[] for i in xrange(n + 1)]
    for i in xrange(n):
        L = [int(t) for t in getList()]
        if v[L[0]]:
            root[L[0]] = 1
            v[L[0]] = 0
        a[L[0]] = L[1]
        for j in xrange(L[2]):
            c[L[0]].append(L[3+j])
            p[L[3+j]] = L[0]
            v[L[3+j]] = 0
            if L[3+j] in root:
                del root[L[3+j]]
    #print c
    q = deque([])
    #print 'len of root %d'%len(root)
    for ROOT in root:
        q.append(ROOT)
    #print q
    path = []
    while len(q):
        left = q.popleft()
        #print q
        #print 'left: %d'%left
        path.append(left)
        for i in xrange(len(c[left])):
            q.append(c[left][i])
    #print path
    ans = 0
    for i in xrange(n-1, 0, -1):
        ans += abs(1 - a[path[i]])
        #print ans, abs(1 - a[path[i]])
        a[p[path[i]]] -= 1 - a[path[i]]
        a[path[i]] = 1
        
    print ans
    n = getInt()
    
