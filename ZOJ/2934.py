#Problem ID: 2934
#Submit Time: 2013-05-24 15:06:52
#Run Time: 350
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

while 1:
    l = getints()
    if len(l) == 1 and l[0] == 0:
        break
    a, b, c, s = l[0], l[1], l[2], l[3]
    one = (1<<16)-1
    zero = 0
    for i in xrange(c):
        one &= s
        zero |= s
        s = (a * s + b) % c
    ans = ['?' for i in xrange(16)]
    for i in xrange(15, -1, -1):
        if one & (1<<i):
            ans[15-i] = '1'
        elif not (zero & (1<<i)):
            ans[15-i] = '0'
    print ''.join(ans)
