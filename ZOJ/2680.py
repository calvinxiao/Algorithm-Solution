#Problem ID: 2680
#Submit Time: 2012-09-10 16:57:24
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

TC = getint()
for tc in xrange(TC):
    s = getlist()
    a = [[0,0,0.0, ''] for i in xrange(5)]
    for i in xrange(5):
        a[i][3] = s[i]
        a[i][0] = int(s[i][0:2])
        if a[i][0] >= 12:
            a[i][0] -= 12
        a[i][1] = int(s[i][3:5])
        diff = 1.0 * a[i][1]/60 - (1.0 * a[i][0]/12 + 1.0 * a[i][1] / 60 / 12)
        if diff < 0.0:
            diff = -diff
        if diff > 0.5:
            diff = 1.0 - diff
        a[i][2] = diff
        #print a[i][0], a[i][1], a[i][2], a[i][3]
    a.sort(key = lambda s: s[0] * 60 + s[1])
    a.sort(key = lambda s: s[2])
    #print a
    print a[2][3]
    
        
