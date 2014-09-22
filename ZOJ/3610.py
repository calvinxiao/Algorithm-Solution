#Problem ID: 3610
#Submit Time: 2014-01-05 18:32:36
#Run Time: 0
#Run Memory: 140
#ZOJ User: calvinxiao

import sys

N = int(sys.stdin.readline())
while N:
	N -= 1
	line = sys.stdin.readline().split()
	print line[1] + ' will survive'