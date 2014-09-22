#Problem ID: 3603
#Submit Time: 2012-10-23 15:46:33
#Run Time: 240
#Run Memory: 320
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

TC = getint()
for tc in xrange(TC):
	n = getint()
	d = {}
	ans = []
	line = getline().strip()
	for c in line:
		if c in d:
			d[c] += 1
		else:
			d[c] = 1
	for i in xrange(n-1):
		line = getline().strip()
		t = {}
		for c in line:
			if c in t:
				t[c] += 1
			else:
				t[c] = 1
		for c in d:
			if not c in t:
				d[c] = 0
			else:
				if d[c] > t[c]:
					d[c] = t[c]
	for c in d:
		for i in xrange(d[c]):
			ans.append(c)
	ans.sort()
	print ''.join(ans)
    
