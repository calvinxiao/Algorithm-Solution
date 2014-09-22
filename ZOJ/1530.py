#Problem ID: 1530
#Submit Time: 2013-08-05 22:51:44
#Run Time: 720
#Run Memory: 452
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

def solve(n):
    if n == 1:
        return 1
    dp = [[0 for j in xrange(n)] for i in xrange(100)]
    pre = [[-1 for j in xrange(n)] for i in xrange(100)]
    for i in xrange(100):
        fi = pow(10, i, n)
        if fi == 0:
            return pow(10, i)
        dp[i][fi] = 1
    for i in xrange(1, 100):
        fi = pow(10, i, n)
        for j in xrange(0, i):
            for k in xrange(1, n):
                if dp[j][k]:
                    t = (fi + k) % n
                    dp[i][t] = 1
                    pre[i][t] = j
                    if t == 0:
                        ans = 0
                        while i >= 0:
                            ans += pow(10, i)
                            i, t = pre[i][t], (t - pow(10, i, n) + n) % n
                        return ans

    
#sys.stdin = open("0.in", "r")
#sys.stdout = open("ans.out", "w")

while 1:
    n = getint()
    if not n:
        break
    print solve(n)

#sys.stdout.flush()
#sys.stdout.close()
