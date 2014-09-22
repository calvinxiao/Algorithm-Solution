#Problem ID: 3702
#Submit Time: 2013-06-19 12:48:45
#Run Time: 980
#Run Memory: 320
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
#sys.stdout = open("0.in", "w")

def G(a, b, i):
    if i == 0:
        return a
    elif i == 1:
        return b
    else:
        i -= 1
        while i:
            i -= 1
            a, b = b, a + b
        return b

tc = getint()
while tc:
    tc -= 1
    i, gi, j = getints()
    a, b, l, r, m = 1, -1, 1, 1000000, -1
    while l < r + 1:
        m = l + r >> 1
        #print 'M ' +str(m)
        g = G(a, m, i)
        if g < gi:
            l = m + 1
        elif g > gi:
            r = m - 1
        else:
            b = m
            print G(a, b, j)
            break
    if b == -1:
        print -1
