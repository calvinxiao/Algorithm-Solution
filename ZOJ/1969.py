#Problem ID: 1969
#Submit Time: 2013-02-18 14:13:12
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

def rec(s):
    l = list(s)
    l.reverse()
    return int(''.join(l))

while 1:
    l = getline().strip()
    a, b = l.split('+')
    b, c = b.split('=')
    #print a, b, c
    if a == '0' and b == '0' and c == '0':
        print 'True'
        break
    if rec(a) + rec(b) == rec(c):
        print 'True'
    else:
        print "False"

    
