#Problem ID: 1582
#Submit Time: 2013-08-06 12:32:46
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
tc = getint()
while tc:
    tc -= 1
    T = getint()
    a = raw_input()
    b = raw_input()
    la, lb = len(a), len(b)
    cnt = 0
    for i in xrange(min(la, lb)):
        if a[i] == b[i]:
            cnt +=2
        else:
            break
    print (la + lb - cnt) * T
