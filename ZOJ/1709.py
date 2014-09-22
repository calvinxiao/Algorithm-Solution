#Problem ID: 1709
#Submit Time: 2012-05-25 22:17:38
#Run Time: 150
#Run Memory: 452
#ZOJ User: calvinxiao

from sys import stdin

x = [0, -1, -1, -1, 0, 1, 1, 1]
y = [1, 1, 0, -1, -1, -1, 0, 1]
while True:
    line = stdin.readline().split(' ')
    m = int(line[0])
    n = int(line[1])
    if m == 0:
        break

    vis = [ [False for j in xrange(n)] for i in xrange(m)]
    a = [ ['' for j in xrange(n)] for i in xrange(m)]
    for i in xrange(m):
        line = stdin.readline().strip('\n')
        a[i] = line

    #print a
    count = 0

    for i in xrange(m):
        for j in xrange(n):
            if not vis[i][j] and a[i][j] == '@':
                count += 1
                stack = []
                stack.append(i*101 + j)
                while len(stack) > 0:
                    temp = stack.pop()
                    ii = temp / 101
                    jj = temp % 101
                    #a[ii][jj] = '*'
                    #print ii, jj
                    vis[ii][jj] = True
                    for k in xrange(8):
                        ti = ii + x[k]
                        if ti < 0 or ti >= m:
                            continue
                        tj = jj + y[k]
                        if tj <0 or tj >=n:
                            continue

                        if not vis[ti][tj] and a[ti][tj] == '@':
                            stack.append(ti * 101 + tj)
                    

                        

    print count
        
