#Problem ID: 1076
#Submit Time: 2012-07-02 00:41:47
#Run Time: 80
#Run Memory: 2904
#ZOJ User: calvinxiao

import sys

def getInt():
    return int(sys.stdin.readline())

def cout(a):
    sys.stdout.write(str(a))

def getList():
    return sys.stdin.readline().strip().split()

while True:
    n = getInt()
    if n == 0:
        break
    
    a = [[0, 0, 0] for j in xrange(n)]
    maxV = 0
    for i in xrange(n):
        line = getList()
        a[i][1] = int(line[0])
        a[i][0] = int(line[1])
        a[i][2] = i
        maxV = max(maxV, a[i][0])
    a.sort()
    #print a
    dp = [[0, 0] for i in xrange(maxV + 1)]
    ansV = 0

    dp[a[0][0]][0] = a[0][0] - a[0][1]
    dp[a[0][0]][0] = 0
    for i in xrange(n):
        for j in xrange(i):
            if a[j][0] >= a[i][1]:
                continue
            add = a[i][0] - a[i][1]
            if dp[a[i][0]][0] <= add + dp[a[j][0]][0]:
                dp[a[i][0]][0] = add + dp[a[j][0]][0]
                dp[a[i][0]][1] = i
                #dp[a[i][1]][2] = a[i][2]
                if dp[a[i][0]][0] > ansV:
                    ansV = dp[a[i][0]][0]
    res = []
    #print ansV
    while maxV > 0:
        if dp[maxV][0] == ansV:
            res.append(a[dp[maxV][1]][2] + 1)
            #print a[dp[maxV][1]]
            ansV -= a[dp[maxV][1]][0] - a[dp[maxV][1]][1]
            maxV = a[dp[maxV][1]][1] - 1
        else:
            maxV -= 1

    res.reverse()
    for i in xrange(len(res)):
        if not i == 0:
            cout(' ')
        cout(res[i])
    print ''
    #print dp[773]
    #print res
    #print dp
            
