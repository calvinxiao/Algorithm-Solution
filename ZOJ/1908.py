#Problem ID: 1908
#Submit Time: 2013-03-20 00:18:57
#Run Time: 20
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

def win(a, c):
    ret = 0
    for i in xrange(3):
        if a[i].count(c) == 3:
            ret += 1
    for j in xrange(3):
        cnt = 0
        for i in xrange(3):
            if a[i][j] == c:
                cnt += 1
        if cnt == 3:
            ret += 1
    cnt = 0
    for i in xrange(3):
        if a[i][i] == c:
            cnt += 1
    if cnt == 3:
        ret += 1
    cnt = 0
    for i in xrange(3):
        if a[2-i][0+i] == c:
            cnt += 1
    if cnt == 3:
        ret += 1
    return ret

n = input()
for nn in xrange(n):
    if nn:
        getline()
    a = []
    xcnt, ocnt = 0, 0
    for i in xrange(3):
        a.append(raw_input())
        xcnt += a[i].count('X')
        ocnt += a[i].count('O')
    good = True
    if xcnt != ocnt + 1 and xcnt != ocnt:
        good = False
    #print xcnt, ocnt, good
    if good:
        xwin, owin = win(a, 'X'), win(a, 'O')
        if xwin > 0 and owin > 0:
            good = False
        if xcnt == ocnt + 1 and owin > 0:
            good = False
        if xwin > 0 and xcnt == ocnt:
            good = False
        #print xwin, owin, good
    if good:
        print 'yes'
    else:
        print 'no'
    
            
