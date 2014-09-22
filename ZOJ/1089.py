#Problem ID: 1089
#Submit Time: 2012-11-21 16:03:45
#Run Time: 40
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getints():
	return [int(num) for num in getlist()]

def getlist():
    return sys.stdin.readline().strip().split()

#sys.stdin = open("0.in", "r")

def rec(a, cur, size, depth):
    if len(cur) == 6:
        print ' '.join([str(num) for num in cur])
        return
    if depth == size:
        return
    if len(cur) + size - depth + 1 < 6:
        return
    for i in xrange(depth, size):
        cur.append(a[i])
        rec(a, cur, size, i+1)
        cur.pop()

pl = False
while 1:
    a = getints()
    if a[0] == 0:
        break
    
    n, a = a[0], a[1:len(a)]
    cur = []
    #print pl
    if pl:
        print ''
    else:
        pl = True
    rec(a, cur, n, 0)
    
    
