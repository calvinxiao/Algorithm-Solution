#Problem ID: 2970
#Submit Time: 2012-08-09 17:30:58
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

cases = getint()
for case in xrange(cases):
    name = getline().strip()
    getline()
    if name == 'Faster':
        print min([int(num) for num in getlist()])
    else:
        print max([int(num) for num in getlist()])

    
