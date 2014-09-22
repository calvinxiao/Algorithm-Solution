#Problem ID: 1284
#Submit Time: 2013-05-09 11:23:30
#Run Time: 30
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

print 'PERFECTION OUTPUT'
while 1:
    a = getints()
    for n in a:
        if not n:
            break
        ans = 0
        for i in xrange(1, n):
            if n % i == 0 and n / i != 1:
                ans += i
        if ans == n:
            print '%5d  PERFECT' % n
        elif ans < n:
            print '%5d  DEFICIENT' % n
        else:
            print '%5d  ABUNDANT' % n
    if a[len(a) - 1] == 0:
        break

print 'END OF OUTPUT'
