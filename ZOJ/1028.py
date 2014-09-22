#Problem ID: 1028
#Submit Time: 2014-06-12 12:04:02
#Run Time: 10
#Run Memory: 140
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

tc = input()
while tc:
    tc -= 1
    a = getints()
    n = a[0]
    a = a[1:]
    good = 0
    if n % 2 == 1:
        good = 1
    else:
        odd, even = 0, 0
        for i in xrange(n):
            if a[i] == 1:
                if i % 2 == 1:
                    odd += 1
                else:
                    even += 1
        if odd == even or odd == even + 1 or even == odd + 1:
            good = 1
    if good:
        print 'YES'
    else:
        print 'NO'
