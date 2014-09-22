#Problem ID: 2164
#Submit Time: 2013-03-19 22:26:57
#Run Time: 140
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
    n, r = getints()
    if not n and not r:
        break
    a = [i+1 for i in xrange(n)]
    for i in xrange(r):
        p, c = getints()
        for j in xrange(n-p-c+1, n-p+1):
            a.append(a[j])
        del a[n-p-c+1:n-p+1]
    print a[n-1]
    


            
