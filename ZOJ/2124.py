#Problem ID: 2124
#Submit Time: 2013-03-19 22:11:09
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

def gao(n):
    sign = 1
    if n < 0:
        n, sign = -n, -1
    for p in xrange(33, 0, -1):
        r = int(pow(1.0*n, 1.0/p)+0.00001)
        if sign == 1 and r ** p == n:
            print p
            break
        elif sign == -1 and r ** p == n and p%2 == 1:
            print p
            break
    
while 1:
    n = input()
    if not n:
        break
    gao(n)


            
