#Problem ID: 1961
#Submit Time: 2013-02-10 00:36:54
#Run Time: 20
#Run Memory: 452
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getints():
	return [int(num) for num in getlist()]

def getlist():
    return sys.stdin.readline().strip().split()

#sys.stdin = open("0.in", "r")

from fractions import *

prime = [1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
while 1:
	c, s = getints()
	if not c and not s:
		break
	if s==0 or c==0:
		print 0
		continue
	ans = 0
	if s in prime:
		ans = c**s + (s-1)*c
	else:
		ans = c**s
		for i in xrange(1, s):
			ans += c ** gcd(i, s)
	cur = s
	if s&1:
		ans += s * (c ** (s/2+1))
		cur += s
	else:
		ans += s/2*(c ** (s/2)) + s/2*(c ** (s/2+1))
		cur += s
	print ans/cur