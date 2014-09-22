#Problem ID: 1938
#Submit Time: 2013-05-30 17:25:22
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

while 1:
    n, k = getints()
    if n == 0 and k == 0:
        break;
    k = min(k, n-k)
    s, x = 1, 1
    for i in xrange(n, n-k, -1):
        s = s * i / x
        x += 1
    print s
    
