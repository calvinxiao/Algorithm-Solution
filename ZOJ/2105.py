#Problem ID: 2105
#Submit Time: 2012-07-03 11:52:52
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def RL():
    return sys.stdin.readline()
def getInt():
    return int(sys.stdin.readline())

def getList():
    return sys.stdin.readline().strip().split()
maxRep = 51
while 1:
    A, B, n = [int(L) for L in getList()]
    if A == 0 and B == 0 and n == 0:
        break
    
    f = [1 for i in xrange(maxRep)]
    for i in xrange(2, maxRep):
        f[i] = (A * f[i-1] + B * f[i-2]) % 7
        #print i, f[i]
    reps = 0
    repe = 0
    for i in xrange(0, maxRep - 1):
        if reps == 0 and repe == 0:
            for j in xrange(i+2, maxRep - 1):
                #print f[i],f[j], f[i+1],f[j+1]
                if f[i] == f[j] and f[i+1] == f[j+1]:
                    reps = i
                    repe = j
                    #print reps, repe
                    break
        else:
            break
    n -= 1
    if n <= reps:
        print f[n]
    else:
        ans = reps + (n - reps) % (repe - reps)
        print f[ans]
