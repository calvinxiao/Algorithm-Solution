#Problem ID: 1414
#Submit Time: 2012-08-19 15:03:58
#Run Time: 40
#Run Memory: 1300
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()


ans = [[[0, 0] for j in xrange(2)] for i in xrange(5010)]
TC = getint()
ans[0][0] = [0, 0]
ans[0][1] = [-1, -1]
ans[1][0] = [1, 1]
ans[1][1] = [-1, -1]
ans[2][0] = [0, 2]
ans[2][1] = [2, 4]
plus = [3, 1]
for i in xrange(3, 5001):
    toplus = plus[i % 2]
    ans[i][0] = [ans[i-1][0][0] + 1, ans[i-1][0][1] + toplus]
    ans[i][1] = [ans[i-1][1][0] + 1, ans[i-1][1][1] + toplus]
for case in xrange(TC):
    x, y = [int(num) for num in getlist()]
    flag = False
    for j in xrange(2):
        if ans[x][j][0] == y:
            flag = True
            print ans[x][j][1]
            break
    if not flag:
        print 'No Number'
    
