#Problem ID: 3693
#Submit Time: 2013-04-04 00:05:22
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
eps = 1e-8

while 1:
    line = getline()
    if not line:
        break
    line = line.split()
    n, w, k = int(line[0]), float(line[1]), int(line[2])
    ans = 0.0;
    n += 2
    ans += 1.0 * w * (n / k) * (k - 1) + eps
    n %= k
    ans += 1.0 * w * n + eps
    print '%.2f' % (ans / 2)
    
            
