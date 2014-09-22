#Problem ID: 3622
#Submit Time: 2013-06-19 16:03:56
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
#sys.stdout = open("0.in", "w")

number = [1, 2, 5, 25, 125]
limit = int(1e20)
a = []
for num in number:
    tnum = num
    while tnum < limit:
        a.append(tnum)
        tnum *= 10
a.sort()
#print a
def f(n):
    l = 0
    r = len(a) - 1
    ret = 0
    while l <= r:
        m = l + r >> 1
        if a[m] <= n:
            l = m + 1
            ret = l
        else:
            r = m - 1
    return ret

def ff(n):
    l = 0
    r = len(a) - 1
    ret = 0
    while l <= r:
        m = l + r >> 1
        if a[m] < n:
            l = m + 1
        else:
            r = m - 1
            ret = r
    return ret

#print a
while 1:
    line = getline()
    if not line:
        break
    m, n = map(int, line.split())
    #print f(n) - ff(m) - 1
    print f(n) - f(m-1)
