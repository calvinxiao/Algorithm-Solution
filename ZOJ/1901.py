#Problem ID: 1901
#Submit Time: 2012-09-17 22:00:26
#Run Time: 110
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

def dis_all(x, y, a):
    n = len(a)
    dis = 0.0
    for i in xrange(n):
        dis += ((x - a[i][0]) * (x - a[i][0]) + (y - a[i][1]) * (y - a[i][1])) ** 0.5
    return dis

N = getint()
a = [[0,0] for i in xrange(N)]

for i in xrange(N):
    a[i][0], a[i][1] = [int(num) for num in getlist()]

dis = 0.0
ansx = a[0][0]
ansy = a[0][1]
MIN = 100000000.0
eps = 1e-8
step = 10000.0
d = [[0, 1], [0, -1],[1, 0], [-1, 0]]

while step > eps:
    flag = True
    while flag:
        flag = False
        for i in xrange(4):
            tx = ansx + step * d[i][0]
            ty = ansy + step * d[i][1]
            tempdis = dis_all(tx, ty, a)
            if tempdis < MIN:
                MIN = tempdis
                ansx = tx
                ansy = ty
                flag = True
    step /= 1.5
                
print '%.0f' % MIN
    
