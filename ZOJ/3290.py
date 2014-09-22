#Problem ID: 3290
#Submit Time: 2013-09-27 08:57:35
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

def doit(n):
    k = []
    s = 1
    while s <= n:
        k.append(s)
        s = s + s + 1
    ans = []
    for kk in k:
        if kk + kk + kk + 1 <= n:
            ans.append(kk)
            n -= kk
        else:
            ans.append(n)
            n = 0
        if n == 0:
            break
    ans.reverse()
    return ans

tc = 0
while 1:
    line = getline()
    if not line:
        break
    if tc:
        print ''
    tc += 1
    n = int(line)
    a = doit(n)
    print len(a)
    print ' '.join([str(num) for num in a])
