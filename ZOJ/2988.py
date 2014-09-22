#Problem ID: 2988
#Submit Time: 2012-09-13 00:53:59
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
    n, unit = getlist()
    if unit == 'kg':
        print '%d %.4f lb' % (tc + 1, float(n) * 2.2046)
    elif unit == 'lb':
        print '%d %.4f kg' % (tc + 1, float(n) * 0.4536)
    elif unit == 'l':
        print '%d %.4f g' % (tc + 1, float(n) * 0.2642)
    else:
        print '%d %.4f l' % (tc + 1, float(n) * 3.7854)
        

    
