#Problem ID: 3179
#Submit Time: 2014-05-16 10:24:38
#Run Time: 10
#Run Memory: 268
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


TC = input()
for tc in xrange(TC):
	x, y = getints()
	a = []
	for i in xrange(8):
		a.append(raw_input())
	t = []
	for i in xrange(6):
		t.append(10**i)
	t.reverse()
	ans = 0
	for i in xrange(6):
		if a[1][i] == 'o':
			ans += 5 * t[i]
	s = [1 for i in xrange(6)]
	for i in xrange(3, 8):
		for j in xrange(6):
			if a[i][j] == '|':
				s[j] = 0
			else:
				ans += t[j] * s[j]
	what = y * (y+1) / 2 - x * (x-1) / 2
	if what == ans:
		print 'No mistake'
	else:
		print 'Mistake'

	if tc != TC - 1:
		getline()
