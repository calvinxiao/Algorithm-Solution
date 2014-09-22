#Problem ID: 1168
#Submit Time: 2014-03-08 03:10:38
#Run Time: 1130
#Run Memory: 404
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

f = [[[1 for k in xrange(21)] for j in xrange(21)] for i in xrange(21)]

def w(a, b, c):
    global f
    if min(a, b, c) <= 0:
        return 1
    else:
        return f[a][b][c]
    

for a in xrange(0, 21):
    for b in xrange(0, 21):
        for c in xrange(0, 21):
            if min(a, b, c) <= 0:
                f[a][b][c] = 1
            elif a < b and b < c:
                f[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
            else:
                f[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

while 1:
    a, b, c = getints()
    if a == -1 and b == -1 and c == -1:
        break
    ans = 1
    if min(a, b, c) <= 0:
        ans = 1
    elif max(a, b, c) > 20:
        ans = w(20, 20, 20)
    else:
        ans = w(a, b, c)
    print 'w(%d, %d, %d) = %d' % (a, b, c, ans)
