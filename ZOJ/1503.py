#Problem ID: 1503
#Submit Time: 2013-06-13 17:36:32
#Run Time: 10
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
#sys.stdout = open("0.in", "w")


f = [[0 for i in xrange(33)] for j in xrange(33)]

for j in xrange(33):
    f[1][j] = 1
    
for i in xrange(33):
    f[i][0] = i

for i in xrange(1, 32):
    for j in xrange(1, 32):
        f[i][j] = f[i-1][j-1] + 1 + f[i-1][j]

tc = 0
while 1:
    tc += 1
    G, L = getints()
    if not G and not L:
        break
    print 'Case %d: %d' % (tc, f[G][L])
    
