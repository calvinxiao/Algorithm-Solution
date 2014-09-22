#Problem ID: 2284
#Submit Time: 2012-09-19 04:19:36
#Run Time: 80
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

ans = [[0 for i in xrange(201)] for j in xrange(21)]

ans[1][0] = 1
for i in xrange(2, 21):
    for j in xrange(201):
        k = 0
        while k < i and j - k >= 0:
            ans[i][j] += ans[i-1][j-k]
            k += 1

while 1:
    n, k = [int(num) for num in getlist()]
    if not n and not k:
        break
    print ans[n][k]




    
