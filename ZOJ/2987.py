#Problem ID: 2987
#Submit Time: 2012-08-22 14:08:00
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
for tc in xrange(1, TC + 1):
    line = getline().rstrip().split()
    n = int(line[0])
    l = len(line[1])
    sys.stdout.write(str(tc) + ' '),
    for i in xrange(l):
        if i + 1 != n:
            sys.stdout.write(line[1][i])
    print ''
    
