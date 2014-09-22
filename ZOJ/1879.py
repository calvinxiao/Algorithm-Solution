#Problem ID: 1879
#Submit Time: 2012-08-16 14:40:08
#Run Time: 50
#Run Memory: 456
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()


while True:
    line = getline()
    if not line:
        break

    a = [int(num) for num in line.split()]
    if len(a) == 0:
        continue
    
    if a[0] == 1:
        print 'Jolly'
        continue
    
    b = [abs(a[i] - a[i-1]) for i in xrange(2, len(a))]
    b.sort()
    flag = True
    for i in xrange(len(b)):
        if b[i] != i + 1:
            flag = False
            break
    #print b
    if flag:
        print 'Jolly'
    else:
        print 'Not jolly'
    
