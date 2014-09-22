#Problem ID: 2481
#Submit Time: 2012-08-13 16:42:04
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
    if line[0] == '0':
        break
    a = [int(num) for num in line.split()]
    b = a[1:len(a)]
    b.sort()
    ans = []
    ans.append(b[0])
    for i in xrange(1, len(b)):
        if b[i] != b[i-1]:
            ans.append(b[i])
    print ' '.join([str(num) for num in ans])
