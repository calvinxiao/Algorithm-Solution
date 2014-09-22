#Problem ID: 2486
#Submit Time: 2013-03-18 10:25:04
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
    line = getline()
    if not line:
        break
    n, p = map(int, line.split())
    print int(pow(1.0 * p, 1.0 / n) + 0.001)

            
