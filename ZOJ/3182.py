#Problem ID: 3182
#Submit Time: 2013-06-20 09:40:25
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
#sys.stdout = open("0.in", "w")

f = range(33)

f[1], f[2] = 1, 2

for i in xrange(3, 33):
    f[i] = f[i-1] + 2 * f[i-2] + 1

tc = getint()
while tc:
    tc -= 1
    n = getint()
    n = int(n)
    print f[n]
