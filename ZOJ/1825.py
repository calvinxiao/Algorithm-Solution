#Problem ID: 1825
#Submit Time: 2012-09-07 01:45:31
#Run Time: 190
#Run Memory: 2152
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

d = {}
a = []
while 1:
    line = getline()
    if not line:
        break
    d[line.strip()] = 1
    a.append(line.strip())

for s in a:
    n = len(s)
    for i in xrange(1, n):
        if s[0:i] in d and s[i:n] in d:
            print s
            break
