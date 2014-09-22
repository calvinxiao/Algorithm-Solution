#Problem ID: 1095
#Submit Time: 2012-12-18 16:04:46
#Run Time: 300
#Run Memory: 472
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

p = [30, 13, 19, 11]
a2 = [2**i for i in xrange(30+1)]
a3 = [3**i for i in xrange(19+1)]
a5 = [5**i for i in xrange(13+1)]
a7 = [7**i for i in xrange(11+1)]
#print a2
#print a7
ans = []
up = 2000000000

for a in xrange(30+1):
    for b in xrange(19+1):
        for c in xrange(13+1):
            for d in xrange(11+1):
                temp = a2[a] * a3[b] * a5[c] * a7[d]
                if temp <= up:
                    ans.append(temp)

ans.sort()
#print ans[0:10]
while 1:
    n = getint()
    if not n:
        break
    num = n % 10
    num10 = n % 100
    s = ''
    if num == 1:
        s = 'st'
    elif num == 2:
        s = 'nd'
    elif num == 3:
        s = 'rd'
    else:
        s = 'th'
    if num10 >= 10 and num10 <= 20:
        s = 'th'
    print 'The %d%s humble number is %d.' % (n, s, ans[n-1])
