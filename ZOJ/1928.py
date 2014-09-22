#Problem ID: 1928
#Submit Time: 2013-08-13 23:32:15
#Run Time: 50
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
    a, b, c, d = getints()
    if (a|b|c|d) == 0:
        break
    ans = 120
    ans += a - b
    if a - b < 0:
        ans += 40
    ans += c - b
    if c - b < 0:
        ans += 40
    ans += c - d
    if c - d < 0:
        ans += 40
    print ans * 9
        
