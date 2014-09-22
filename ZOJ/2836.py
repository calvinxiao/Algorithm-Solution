#Problem ID: 2836
#Submit Time: 2014-05-20 10:19:45
#Run Time: 30
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

def gcd(a, b):
    while a != 0:
        a, b = b % a, a
    return b

while 1:
    line = getline()
    if not line:
        break
    n, m = map(int, line.split())
    a = getints()
    ans = 0
    for i in xrange(1, 1 << n):
        cnt = 0
        lcm = 1
        for j in xrange(n):
            if (1<<j) & i:
                lcm = lcm * a[j] / gcd(lcm, a[j])
                cnt += 1
        if cnt & 1:
            ans += m / lcm
        else:
            ans -= m / lcm
    print ans
