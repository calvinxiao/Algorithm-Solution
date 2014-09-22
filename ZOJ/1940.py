#Problem ID: 1940
#Submit Time: 2014-03-25 10:58:54
#Run Time: 360
#Run Memory: 3844
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

while 1:
    X, Y, Z = getints()
    if X + Y + Z == 0:
        break
    sx, sy, sz, tx, ty, tz = [0 for i in xrange(6)]
    g = [['' for j in xrange(Y)] for i in xrange(X)]
    for i in xrange(X):
        for j in xrange(Y):
            l = raw_input()
            g[i][j] = l
        getline()
    #print g
    for i in xrange(X):
        for j in xrange(Y):
            for k in xrange(Z):
                if g[i][j][k] == 'S':
                    sx, sy, sz = i, j, k
                elif g[i][j][k] == 'E':
                    tx, ty, tz = i, j, k
    q = [[sx, sy, sz]]
    d = [[[9999 for i in xrange(Z)] for j in xrange(Y)] for i in xrange(X)]
    inq = [[[0 for i in xrange(Z)] for j in xrange(Y)] for i in xrange(X)]
    d[sx][sy][sz] = 0
    inq[sx][sy][sz] = 1
    s = 0
    dx = [-1, 1, 0, 0, 0, 0]
    dy = [0, 0, -1, 1, 0, 0]
    dz = [0, 0, 0, 0, -1, 1]
    while s < len(q):
        topx, topy, topz = q[s]
        inq[topx][topy][topz] = 0
        s += 1
        for i in xrange(6):
            nx, ny, nz = topx + dx[i], topy + dy[i], topz + dz[i]
            if 0 <= nx and nx < X and 0 <= ny and ny < Y and 0 <= nz and nz < Z and g[nx][ny][nz] != '#':
                if d[nx][ny][nz] > d[topx][topy][topz] + 1:
                    d[nx][ny][nz] = d[topx][topy][topz] + 1
                    if not inq[nx][ny][nz]:
                        q.append([nx, ny, nz])
                        inq[nx][ny][nz] = 1
    if d[tx][ty][tz] == 9999:
        print 'Trapped!'
    else:
        print 'Escaped in %d minute(s).' % d[tx][ty][tz]
