#Problem ID: 1824
#Submit Time: 2012-09-07 02:14:05
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

dirs = ['N', 'E', 'S', 'W']
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

while 1:
    line = getline()
    if not line:
        break
    n, m = [int(num) for num in line.split()]
    a = []
    for i in xrange(n):
        a.append(getline())
    x, y = [int(num) - 1 for num in getlist()]
    
    di = 0
    while 1:
        line = getline().strip()
        isQ = False
        for i in xrange(len(line)):
            if line[i] == 'Q':
                isQ = True
                break
            elif line[i] == ' ':
                continue
            elif line[i] == 'L':
                di = (di - 1 + 4) % 4
            elif line[i] == 'R':
                di = (di + 1 + 4) % 4
            elif line[i] == 'F':
                newx = x + dx[di]
                newy = y + dy[di]
                if 0 <= newx and newx < n and 0 <= newy and newy < m:
                    if a[newx][newy] != '*':
                        x, y = newx, newy
        if isQ:
            break
    print x + 1, y + 1, dirs[di]
    getline()
            

        
