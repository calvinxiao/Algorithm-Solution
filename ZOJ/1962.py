#Problem ID: 1962
#Submit Time: 2012-09-27 15:25:45
#Run Time: 80
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

ans = [1]
a = 1
b = 2
MAX = 10 ** 100
while b < MAX:
	ans.append(b)
	a, b = b, a + b
n = len(ans)

while 1:
	c, d = [int(num) for num in getlist()]
	if not c and not d:
		break
	cnt = 0
	for i in xrange(n):
		if ans[i] >= c and ans[i] <= d:
			cnt += 1
	print cnt



    
