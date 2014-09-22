#Problem ID: 3191
#Submit Time: 2013-04-24 10:15:49
#Run Time: 10
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

while 1:
    n = getint()
    if n == -1:
        break
    now = 3
    while n > 29:
        n -= 30
        now -= 1
        if now < 0:
            now += 12
    if n == 0:
        print "Exactly %d o'clock" % now
    else:
        before = now - 1
        if before < 0:
            before += 12
        print "Between %d o'clock and %d o'clock" % (before, now)
