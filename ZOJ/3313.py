#Problem ID: 3313
#Submit Time: 2014-03-01 02:05:14
#Run Time: 10
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

n = input()
for nn in xrange(n):
    x = input() * 1.0
    print '%.2f' % (x * 480)
