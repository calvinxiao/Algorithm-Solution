#Problem ID: 2437
#Submit Time: 2014-05-25 16:24:57
#Run Time: 280
#Run Memory: 5840
#ZOJ User: calvinxiao

import sys
#sys.stdin = open('in.txt', 'r')

TC = input()
for tc in xrange(TC):
    sys.stdin.readline()
    if tc:
        print ''
    n = input()
    g = [[] for i in xrange(n)]
    x = [[] for i in xrange(n)]
    zero = []
    for i in xrange(n):
        g[i] = map(int, raw_input().split())
        for j in xrange(n):
            if g[i][j] != 0:
                x[i].append([j, g[i][j]])
            else:
                zero.append([i, j])
    for p, q in zero:
        d, v, cnt = 999, 0, 0
        for j in xrange(n):
            if abs(j - p) > d:
                   break
            l, r = -1, len(x[j])
            #print l, r
            while l + 1< r:
                mid = (l + r) >> 1
                if x[j][mid][0] < q:
                    l = mid
                else:
                    r = mid
            #print x[j], q, l, r
            if r >= 0 and r < len(x[j]):
                k = x[j][r][0]
                dd = abs(p - j) + abs(q - k)
                if dd < d:
                    d = dd;
                    v = x[j][r][1]
                    cnt = 1
                elif dd == d:
                    cnt += 1
            if r > 0:
                r -= 1
                k = x[j][r][0]
                dd = abs(p - j) + abs(q - k)
                if dd < d:
                    d = dd;
                    v = x[j][r][1]
                    cnt = 1
                elif dd == d:
                    cnt += 1
        if cnt == 1:
            g[p][q] = v

    for i in xrange(n):
        print ' '.join([str(num) for num in g[i]])




















    
