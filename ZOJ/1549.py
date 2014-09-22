#Problem ID: 1549
#Submit Time: 2013-07-02 08:59:07
#Run Time: 810
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

#sys.stdin = open("amusing.in", "r")
#sys.stdout = open("amusing.out", "w")

def func(n, num, ln):
    nLength = len(ln)
    ret = 0
    ten = 10
    while num * ten <= n:
        #print num, ten, n
        nt = num * ten
        L, R = 0, ten-1
        toadd = -1
        if nt + ten - 1 <= n:
            toadd = ten - 1
        else:
            while L <= R:
                mid = L + R >> 1
                if nt + mid <= n:
                    toadd = mid
                    L = mid + 1
                else:
                    R = mid - 1
        ret += toadd + 1
        ten *= 10
    return ret + 1

def get(n, k, ln, lk):
    ret = 0
    kLength = len(lk)
    num = 0
    for i in xrange(kLength):
        num *= 10
        start = 0
        if i == 0:
            start = 1
        for j in xrange(start, lk[i]):
            ret += func(n, num+j, ln)
        num += lk[i]
        #print num
    return ret + kLength
            
#print get(100000000888888879, 100000001)

while 1:
    line = sys.stdin.readline()
    if not line:
        break
    K, M = map(int, line.split())
    lk = map(int, list(str(K)))
    L, R = K, int(1e18)
    ans = 0
    while L <= R:
        mid = (L + R) >> 1
        ln = map(int, list(str(mid)))
        ret = get(mid, K, ln, lk)
        #print L, R, mid, ret
        if ret >= M:
            R = mid - 1
            if ret == M:
                ans = mid
        else:
            L = mid + 1

    print ans
