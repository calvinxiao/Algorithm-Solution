#Problem ID: 2186
#Submit Time: 2012-09-10 13:52:57
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

crash = True
a = [int(num) for num in getlist()]
for i in xrange(3):
    if a[i] <= 168:
        print 'CRASH %d' % a[i]
        crash = True
        break
if not crash:
    print 'NO CRASH'
