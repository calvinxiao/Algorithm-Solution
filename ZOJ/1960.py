#Problem ID: 1960
#Submit Time: 2013-02-10 01:13:25
#Run Time: 350
#Run Memory: 2780
#ZOJ User: calvinxiao

import sys

#sys.stdin = open("0.in", "r")
words = []
idx = 0
didx = {}
d = {}

while 1:
	line = sys.stdin.readline().strip()
	if not line:
		break
	l = list(line)
	l.sort()
	l = ''.join(l)
	if not l in d:
		d[l] = 1
		didx[l] = idx
		words.append([line])
		idx += 1
	else:
		d[l] += 1
		words[didx[l]].append(line)
for i in xrange(idx):
	words[i].sort()
for i in xrange(5):
	if len(d) == 0:
		break
	ma = 0
	ml = []
	for l in d:
		ma = max(ma, d[l])
	for l in d:
		if d[l] == ma:
			ml.append(didx[l])
	s = words[ml[0]][0]
	ma = ml[0]
	for j in xrange(len(ml)):
		if words[ml[j]][0] < s:
			ma = ml[j]
			s = words[ml[j]][0]
	print "Group of size %d:" % len(words[ma]),
	ans = set(words[ma])
	ans = list(ans)
	ans.sort()
	print ' '.join(ans),
	print '.'
	l = words[ma][0]
	l = list(l)
	l.sort()
	l = ''.join(l)
	del d[l]
