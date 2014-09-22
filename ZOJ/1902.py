#Problem ID: 1902
#Submit Time: 2012-08-29 10:32:41
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

while True:
    line = getline()
    if not line:
        break
    n, k = [int(num) for num in line.split()]
    d= {}
    for i in xrange(n):
        lst = getlist()
        d[lst[0]] = int(lst[1])
    for i in xrange(k):
        line = ''
        while 1:
            newline = getline()
            if newline[0] == '.':
                break
            line += newline
        line = line.split()
        #print line
        ans = 0
        for key in d:
            if key in line:
                #print key
                ans += d[key] * line.count(key)
        print ans

    
