#Problem ID: 1730
#Submit Time: 2013-03-09 16:19:00
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

TC = getint()
while TC:
    TC -= 1
    n = input()
    print (n/2)*(n/2-1) + (n%2==1) * (n/2)
