#Problem ID: 2850
#Submit Time: 2012-09-08 23:58:45
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

#sys.stdin = open('in.txt', 'r')

def getints():
    return [int(num) for num in sys.stdin.readline().split()]

while 1:
    n, m = getints()
    if n == 0 and m == 0:
	break
    cnt = n * m
    g = []
    for i in xrange(n):
	g.append(getints())
    for i in xrange(n):
	for j in xrange(m):
	    if g[i][j] == 1:
		cnt -= 1
    yes = True
    for i in xrange(n):
	for j in xrange(m):
	    if g[i][j] == 0:
                if i < n -1 and g[i+1][j] == 0:
                    yes = False
                    break
		if j < m - 1 and g[i][j+1] == 0:
		    yes = False
		    break
    #print cnt, yes
    if cnt == 0:
	yes = False
    if yes:
	print 'Yes'
    else:
	print 'No'
	
