#Problem ID: 1093
#Submit Time: 2012-07-02 02:54:45
#Run Time: 390
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getInt():
    return int(sys.stdin.readline())

def cout(a):
    sys.stdout.write(str(a))

def getList():
    return sys.stdin.readline().strip().split()

def Check(a, b, c, d):
    if a * b <= c * d:
        return False
    if a > b:
        a, b = b, a
    if c > d:
        c, d = d, c
    if a <= c or b <= d:
        return False
    #print a, b, c, d, True
    return True
            
def rec(dp, a, I, H):
    ''' answer in dp[I][H], if we choose the Ith block with the Hth as height'''
    #print ans
    global n
    if not dp[I][H] == -1:
        return dp[I][H]
    dim1 = []
    for j in xrange(3):
        if not j == H:
            dim1.append(a[I][j])
    dim1.append(a[I][H])
    ans1 = 0
    #dim[2] == a[I][H] the height we choose
    for i in xrange(n):
        for h in xrange(3):
            dim2 = []
            for j in xrange(3):
                if not j == h:
                    dim2.append(a[i][j])
            dim2.append(a[i][h])
            if Check(dim1[0], dim1[1], dim2[0], dim2[1]):
                ans1 = max(ans1, rec(dp, a, i, h))
            
    ans1 += dim1[2]
    dp[I][H] = ans1
    return ans1
            

#global
n = 0
a = [[0, 0, 0] for i in xrange(30)]
CASE = 0
while True:
    n = getInt()
    if n == 0:
        break
    CASE += 1
    ans = 0
    dp = [[-1, -1, -1] for i in xrange(n)]
    for i in xrange(n):
        a[i][0], a[i][1], a[i][2]  = [int(L) for L in getList()]

    for ii in xrange(n):
        for hh in xrange(3):
            #print i, H, rec(dp, a, i, H)
            ans = max(ans, rec(dp, a, ii, hh))
            
    print 'Case %d: maximum height = %d' % (CASE, ans)
    

    
