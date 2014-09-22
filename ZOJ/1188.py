#Problem ID: 1188
#Submit Time: 2014-03-08 02:48:50
#Run Time: 140
#Run Memory: 140
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

tc = input()
while tc:
    tc -= 1
    getline()
    n, m = getints()
    a = []
    for i in xrange(m):
        a.append([0, getline().strip()])
    for j in xrange(m):
        s = a[j][1]
        cnt = 0
        for i in xrange(n):
            for k in xrange(i + 1, n):
                if ord(s[i]) > ord(s[k]):
                    cnt += 1
        a[j][0] = cnt
    a.sort()
    for i in xrange(m):
        print a[i][1]
    if tc:
        print ''
