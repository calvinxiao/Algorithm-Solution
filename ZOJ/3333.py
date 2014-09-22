#Problem ID: 3333
#Submit Time: 2013-04-19 15:26:11
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

tc = input()
while tc:
    tc -= 1
    c, a, b = getints()
    a = c - a
    if a < 0:
        a = -a
    b = c - b
    if b < 0:
        b = -b
    if a < b:
        print 'A'
    else:
        print 'B'
