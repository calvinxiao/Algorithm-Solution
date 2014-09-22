#Problem ID: 1454
#Submit Time: 2012-08-18 01:01:56
#Run Time: 640
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getints():
    return [int(num) for num in getlist()]

def getlist():
    return sys.stdin.readline().strip().split()



N = getint()
while N:
    hire, salary, fire = getints()
    qty = getints()
    dp = [0 for i in xrange(N)]
    dpnext = [0 for i in xrange(N)]
    MAX = 10000000
    for i in xrange(N):
        for j in xrange(N):
            if qty[j] >= qty[i]:
                if i == 0:
                    dp[j] = 0 + hire * qty[j] + salary * qty[j]
                    dpnext[j] = dp[j]
                else:
                    #dpnext[j] = {min(dp[k] + hire or fire + salary where k is good}
                    temp = MAX
                    for k in xrange(N):
                        if qty[k] >= qty[i-1]:
                            HIRE = 0
                            FIRE = 0
                            if qty[k] <= qty[j]:
                                HIRE = hire * (qty[j] - qty[k])
                            else:
                                FIRE = fire * (qty[k] - qty[j])
                            SALARY = salary * qty[j]
                            temp = min(temp, dp[k] + HIRE + FIRE + SALARY)
                    dpnext[j] = temp
        dpnext, dp = dp, dpnext
    ans = MAX
    for i in xrange(N):
        if qty[i] >= qty[N-1]:
            ans = min(ans, dp[i])
    print ans
    N = getint()
                
    

    
