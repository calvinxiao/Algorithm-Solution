#Problem ID: 1240
#Submit Time: 2012-08-30 21:04:00
#Run Time: 10
#Run Memory: 444
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
    print 'String #%d' % (tc + 1)
    line = getline().strip()
    for s in line:
        if s == 'Z':
            sys.stdout.write('A')
            continue
        sys.stdout.write(chr(ord(s) + 1))
    print '\n'

    
