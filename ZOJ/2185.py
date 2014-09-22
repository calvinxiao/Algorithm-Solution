#Problem ID: 2185
#Submit Time: 2012-09-20 04:59:40
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


while 1:
    line = getline()
    if not line:
        break
    n = int(line)
    a = 0
    for i in xrange(5000):
        a += i
        if a == n or a + i + 1 > n:
            ansi = 0
            ansj = 0
            if a == n:
                ansi = i
                ansj = 1
                if i % 2 == 1:
                    ansi, ansj = ansj, ansi
            else:
                ansi = n - a
                ansj = i + 2 - n + a
                if i % 2 == 0:
                    ansi, ansj = ansj, ansi
            print 'TERM %d IS %d/%d' % (n, ansi, ansj)
            break

    
