#Problem ID: 1151
#Submit Time: 2012-08-16 01:02:36
#Run Time: 90
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

cases = int(sys.stdin.readline())

for case in xrange(cases):
    sys.stdin.readline()
    n = int(sys.stdin.readline())
    for i in xrange(n):
	line = sys.stdin.readline().rstrip().split()
	line = [L[::-1] for L in line]
	print ' '.join(line)
    if case < cases - 1:
	print ''
