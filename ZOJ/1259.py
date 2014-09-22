#Problem ID: 1259
#Submit Time: 2013-02-18 18:07:32
#Run Time: 410
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

#should use SFPA....
#sys.stdin = open("0.in", "r")

tc = 0
while 1:
    tc += 1
    n = getint()
    if not n:
        break
    while 1:
        b = getints()
        #print b
        if b[0] == 0:
            print ''
            break
        a = []
        start = 1
        for num in b:
            if not len(a):
                a.append(start)
                start += 1
            while start <= n and a[-1] != num:
                a.append(start)
                start += 1
            if a[-1] == num:
                a.pop()
            else:
                break
        if start > n and not len(a):
            print 'Yes'
        else:
            print 'No'
