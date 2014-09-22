#Problem ID: 1608
#Submit Time: 2014-05-14 15:26:30
#Run Time: 0
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

while 1:
	line = getline()
	if not line:
		break
	a, b, r1, r2 = map(float, line.split())
	if min(a, b) < max(r1*2, r2*2) + 0.01:
		print 'No'
	else:
		x1, y1 = r1, r1
		x2, y2 = a - r2, b - r2
		d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
		dd = (r1 + r2) ** 2
		if dd < d:
			print 'Yes'
		else:
			print 'No'
