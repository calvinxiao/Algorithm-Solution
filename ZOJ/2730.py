#Problem ID: 2730
#Submit Time: 2013-08-15 19:54:40
#Run Time: 100
#Run Memory: 320
#ZOJ User: calvinxiao


import sys

def getline():
    return sys.stdin.readline()

def getint():
    return input()

def getints():
	return map(int, raw_input().split())

def getlist():
    return raw_input().split()

#sys.stdin = open("0.in", "r")

def doit(n):
    if n == 1:
        return [0]
    g = [[0 for i in xrange(n)] for j in xrange(n)]
    a = []
    a.append(n-1)
    while 1:
        t = a[len(a)-1]
        update = 0
        for i in xrange(n):
            if not i == t and not g[t][i]:
                update = 1
                a.append(i)
                g[t][i], g[i][t] = 1, 1
                break
        if not update:
            break
    a.pop()
    return a

while 1:
    line = getline()
    if not line:
        break
    n = int(line)
    a = doit(n)
    print len(a)
    print ' '.join([str(num) for num in a])
