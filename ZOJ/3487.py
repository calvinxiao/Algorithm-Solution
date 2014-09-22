#Problem ID: 3487
#Submit Time: 2012-08-20 12:43:26
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
for i in xrange(TC):
    n = getint()
    if (n/10)%10 == 1:
        print str(n)+'th'
    else:
        lastDigit = n % 10
        if lastDigit == 1:
            print str(n)+'st'
        elif lastDigit == 2:
            print str(n)+'nd'
        elif lastDigit == 3:
            print str(n)+'rd'
        else:
            print str(n)+'th'

    
