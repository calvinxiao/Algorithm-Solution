#Problem ID: 2710
#Submit Time: 2013-02-06 01:16:22
#Run Time: 510
#Run Memory: 980
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

    
def abc(x1, y1, x2, y2):
    a, b, c = 0, 0, 0
    if x1 == x2:
        a, b, c = 1, 0, -x1
    elif y1 == y2:
        a, b, c = 0, 1, -y1
    else:
        a, b = y2 - y1, x1 - x2
        c = -1.0 * (a * x1 + b * y1)
    return [1.0 * a, 1.0 * b, 1.0 * c]

while 1:
    line = getline()
    if not line:
        break
    n, c = map(int, [x for x in line.split()])
    f = [[1e9 for j in xrange(n+1)] for i in xrange(n+1)]
    d = [[0.0, 0.0, 0.0] for i in xrange(n+1)]
    x1, y1, x2, y2 = getints()
    x3, y3, x4, y4 = getints()
    a1, b1, c1 = abc(x1, y1, x2, y2)
    a2, b2, c2 = abc(x3, y3, x4, y4)
    #print a1, b1, c1
    #print a2, b2, c2
    for i in xrange(1, n+1):
        x, y, w = getints()
        d[i][1] =1.0 * w * (abs(c1 + a1*x + b1 * y) / pow((a1*a1 + b1*b1), 0.5))
        d[i][2] =1.0 * w * (abs(c2 + a2*x + b2 * y) / pow((a2*a2 + b2*b2), 0.5))
        #print '%d %d %f' % (i, 1, d[i][1])
        #print '%d %d %f' % (i, 2, d[i][2])
        
    f[0][0] = 0.0
    for i in xrange(1, n+1):
        f[i][0] = f[i-1][0] + d[i][2]
        f[i][i] = f[i-1][i-1] + d[i][1]
        for j in xrange(1, i):
            f[i][j] = min(f[i-1][j] + d[i][2], f[i-1][j-1] + d[i][1])
    ansj = 0
    ma = 1e9
    
    for j in xrange(1, n+1):
        if abs(n - j - j) <= c:
            if ma - f[n][j] > 1e-9:
                ansj, ma = j, f[n][j]
    #print ansj, ma
    ans = []
    for i in xrange(n, 0, -1):
        if ansj == 0:
            ans.append(2)
            continue
        t = f[i-1][ansj-1] + d[i][1]
        if abs(t - f[i][ansj]) < 1e-9:
            ansj = ansj - 1
            ans.append(1)
        else:
            ans.append(2)
    #print ' '.join(str(x) for x in ans)
    ans.reverse()
    print ' '.join(str(x) for x in ans)
    print ''
    getline()
    