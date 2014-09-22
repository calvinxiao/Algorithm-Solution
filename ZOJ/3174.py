#Problem ID: 3174
#Submit Time: 2012-09-13 16:27:08
#Run Time: 30
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
    a, b = [int(num) for num in getlist()]
    cnt = 0
    for i in xrange(a, b+1):
        two = i % 100
        s = int(two ** 0.5)
        if s * s == two and s < 13 and s > 0:
            cnt += 1
        three = i % 1000
        if three != two:
            s = int(three ** 0.5)
            if s * s == three and s < 13 and s > 0:
                cnt += 1
    print cnt
    
