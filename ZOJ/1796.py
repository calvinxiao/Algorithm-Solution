#Problem ID: 1796
#Submit Time: 2013-03-09 15:41:47
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
    a = getints()
    if sum(a) == 0:
       break
    diff = 0
    for i in xrange(0, 6, 2):
        diff += a[i+1] - a[i]
    total = a[0] + a[1]
    a = total + diff >> 1
    b = total - a
    print "Anna's won-loss record is %d-%d." % (a, b)
