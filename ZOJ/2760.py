#Problem ID: 2760
#Submit Time: 2014-05-25 15:20:01
#Run Time: 3560
#Run Memory: 15452
#ZOJ User: calvinxiao

import sys
from collections import deque

class MaxFlowDinic:
    inf = int(1e9)
    
    class Edge:
        # redge will be add dynamically
        def __init__(self, to, cap):
            self.to = to
            self.cap = cap
            #self.redge = 0

    def __init__(self, n):
        self.n = n
        self.g = [[] for i in xrange(n)]

    def addEdge(self, u, v, w):
        edge = self.Edge(v, w)
        redge = self.Edge(u, 0)
        edge.redge = redge
        redge.redge = edge
        self.g[u].append(edge)
        self.g[v].append(redge)

    def bfs(self, g, s, t):
        q = deque()
        q.append(s)
        self.lv = [-1 for i in xrange(self.n)]
        self.lv[s] = 0
        while q:
            u = q.popleft()
            for e in g[u]:
                if self.lv[e.to] == -1 and e.cap > 0:
                    self.lv[e.to] = self.lv[u] + 1
                    q.append(e.to)
        return not self.lv[t] == -1
        
    def dfs(self, g, lv, pointer, s, t, flow):
        if s == t:
            return flow
        lenGS = len(g[s])
        while pointer[s] < lenGS:
            e = g[s][pointer[s]]
            if e.cap > 0 and lv[s] < lv[e.to]:
                d = self.dfs(g, lv, pointer, e.to, t, min(flow, e.cap))
                if d > 0:
                    e.cap -= d
                    e.redge.cap += d
                    return d
            pointer[s] += 1
        return 0
    
            
    def maxflow(self, s, t):
        ans = 0
        while self.bfs(self.g, s, t):
            pointer = [0 for i in xrange(n)]
            while 1:
                anyFlow = self.dfs(self.g, self.lv, pointer, s, t, self.inf)
                if anyFlow == 0:
                    break
                ans += anyFlow
        return ans

#sys.stdin = open('in.txt', 'r')
while 1:
    line = sys.stdin.readline()
    if not line:
        break
    n = int(line)
    d = [[19880325 for i in xrange(n)] for j in xrange(n)]
    g = [[] for i in xrange(n)]
    for i in xrange(n):
        g[i] = map(int, raw_input().split())
        for j in xrange(n):
            if i == j:
                g[i][j] = 0
            if g[i][j] >= 0:
                d[i][j] = g[i][j]
    s, t = map(int, raw_input().split())
    if s == t:
        print 'inf'
        continue

    for k in xrange(n):
        for i in xrange(n):
            for j in xrange(n):
                if d[i][j] > d[i][k] + d[k][j]:
                    d[i][j] = d[i][k] + d[k][j]

    mf = MaxFlowDinic(n)
    for i in xrange(n):
        for j in xrange(n):
            if g[i][j] > -1 and d[s][i] + d[j][t] + g[i][j] == d[s][t]:
                mf.addEdge(i, j, 1)
                
    print '%d' % mf.maxflow(s, t)
    