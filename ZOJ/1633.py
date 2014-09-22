#Problem ID: 1633
#Submit Time: 2013-02-10 01:41:07
#Run Time: 150
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

#sys.stdin = open("0.in", "r")
A = '^__^'
B = 'T.T'
w = 'T.T^__^T.TT.T^__^T.T^__^T.TT.T^__^T.TT.T^__^'
L = len(w)
f = [4, 3]
ma = 2 ** 64
while f[len(f) - 1] < ma:
	f.append(f[len(f) - 1] + f[len(f) - 2])
while 1:
	line = sys.stdin.readline()
	if not line:
		break
	n = int(line)
	for i in xrange(len(f) - 1, 0, -1):
		if n < L:
			break
		if n > f[i]:
			n -= f[i]
	print w[n-1]