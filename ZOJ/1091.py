#Problem ID: 1091
#Submit Time: 2012-11-21 16:27:31
#Run Time: 330
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

#sys.stdin = open("0.in", "r")

def toint(s):
    num = (ord(s[0]) - ord('a')) * 8 + ord(s[1]) - ord('1')
    return num

dx = [-2, -1, 1, 2, 2, 1, -1, -2]
dy = [-1, -2, -2, -1, 1, 2, 2, 1]
g = [[1000000000 for i in xrange(64)] for j in xrange(64)]
for i in xrange(64):
    g[i][i] = 0
for i in xrange(64):
    x, y = i / 8, i % 8
    for j in xrange(8):
        nx, ny = x + dx[j], y + dy[j]
        if 0 <= nx and nx < 8 and 0 <= ny and ny < 8:
            k = nx * 8 + ny
            g[i][k] = g[k][i] = 1
for k in xrange(64):
    for i in xrange(64):
        for j in xrange(64):
            if g[i][j] > g[i][k] + g[k][j]:
                g[i][j] = g[i][k] + g[k][j]
while 1:
    line = getline()
    if not line:
        break
    s1, s2 = line.strip().split()
    a1, a2 = toint(s1), toint(s2)
    #print s1, s2, a1, a2
    print 'To get from %s to %s takes %d knight moves.' % (s1, s2, g[a1][a2])
