#Problem ID: 1295
#Submit Time: 2012-08-30 21:38:19
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
    line = getline().strip()
    print line[::-1]

