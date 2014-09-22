#Problem ID: 1292
#Submit Time: 2012-08-30 23:14:47
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

TC = getint()
for tc in xrange(TC):
    getline()
    ans = 0
    while 1:
        n = getint()
        if not n:
            print ans
            if tc != TC - 1:
                print ''
            break
        ans += n
