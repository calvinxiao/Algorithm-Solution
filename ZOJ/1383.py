#Problem ID: 1383
#Submit Time: 2013-03-07 14:32:43
#Run Time: 0
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

T = getint()
while T:
    T -= 1
    num = getint()
    ans = []
    for i in xrange(32):
        if (1<<i) & num:
            ans.append(i)
    print ' '.join([str(num) for num in ans])
    
