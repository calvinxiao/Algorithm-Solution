#Problem ID: 1649
#Submit Time: 2014-08-27 10:40:54
#Run Time: 1060
#Run Memory: 1444
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return input()

def getints():
	return map(int, raw_input().split())

def getlist():
    return raw_input().split()

#sys.stdin = open("0.in", "r")

import Queue

while 1:
    line = getline()
    if not line:
        break
    n, m = map(int, line.split())
    g = []
    for i in xrange(n):
        g.append(raw_input())
    BIG = 1000000000
    f = [[BIG for i in xrange(m)] for i in xrange(n)]
    x, y = -1, -1
    for i in xrange(n):
        for j in xrange(m):
            if g[i][j] == 'a':
                x, y = i, j
                break
        if x != -1:
            break
    q = Queue.Queue()
    inq = set([])
    q.put((x, y))
    inq.add((x, y))
    f[x][y] = 0
    dxy = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    while not q.empty():
        tx, ty = q.get()
        inq.remove((tx, ty))
        for dx, dy in dxy:
            nx, ny = tx + dx, ty + dy
            if 0 <= nx and nx < n and 0 <= ny and ny < m:
                putin = False
                if g[nx][ny] == '.' or g[nx][ny] == 'r':
                    if f[nx][ny] > f[tx][ty] + 1:
                        putin = True
                        f[nx][ny] = f[tx][ty] + 1
                elif g[nx][ny] == 'x':
                    if f[nx][ny] > f[tx][ty] + 2:
                        putin = True
                        f[nx][ny] = f[tx][ty] + 2
                if putin:
                    if (nx, ny) not in inq:
                        q.put((nx, ny))
                        inq.add((nx, ny))
    ans = BIG
    for i in xrange(n):
        for j in xrange(m):
            if g[i][j] == 'r':
                if f[i][j] < ans:
                    ans = f[i][j]
    if ans == BIG:
        print 'Poor ANGEL has to stay in the prison all his life.'
    else:
        print ans