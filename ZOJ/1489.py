#Problem ID: 1489
#Submit Time: 2012-08-19 04:58:05
#Run Time: 580
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getints():
    return [int(num) for num in getlist()]

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    line = getline()
    if not line:
        break
    n = int(line)
    a = 2
    x = 1
    flag = False
    if n % 2 == 0 or n == 1:
        print '2^? mod %d = 1' % (n)
    else:
        while 1:
            a *= 2
            x += 1
            a %= n
            if a == 1:
                flag = True
                break
        if flag:
            print '2^%d mod %d = 1' % (x, n)
        else:
            print '2^? mod %d = 1' % (n)
