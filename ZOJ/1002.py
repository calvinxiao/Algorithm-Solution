#Problem ID: 1002
#Submit Time: 2012-06-06 22:09:21
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys
p = []
n = 0

def check(i, j):
    k = 1
    while i-k >= 0:
        if p[i-k][j] == 2:
            break
        elif p[i-k][j] == 1:
            return False
        k += 1

    k = 1
    while i+k < n:
        if p[i+k][j] == 2:
            break
        elif p[i+k][j] == 1:
            return False
        k += 1

    k = 1
    while j-k >= 0:
        if p[i][j-k] == 2:
            break
        elif p[i][j-k] == 1:
            return False
        k += 1

    k = 1
    while j+k < n:
        if p[i][j+k] == 2:
            break
        elif p[i][j+k] == 1:
            return False
        k += 1

    return True
    
def rec(a):
    if a == n*n: return 0
    i = a/n
    j = a%n
    if p[i][j] == 2:
        #a wall
        return rec(a+1)
    else:
        yes = 0
        if check(i, j):
            p[i][j] = 1
            yes = 1 + rec(a+1)
        p[i][j] = 0
        no = rec(a+1)
        return max(yes, no)

while True:
    n = int(sys.stdin.readline())
    if not n:
        break

    p = [[0 for i in xrange(n)] for j in xrange(n)]
    
    for i in xrange(n):
        line = sys.stdin.readline()
        for j in xrange(n):
            if line[j] == 'X':
                p[i][j] = 2

    print rec(0)

    
