#Problem ID: 2501
#Submit Time: 2012-05-24 17:02:07
#Run Time: 200
#Run Memory: 828
#ZOJ User: calvinxiao

import sys

t = int(sys.stdin.readline())
for tt in range(t):
    n = int(sys.stdin.readline())
    a = [0 for i in xrange(n)]
    e = [0 for i in xrange(n)]
    b = [0 for i in xrange(n)]
    sumb = [0 for i in xrange(n)]
    
    maxe = 0
    maxb = 0
    tempe = 0
    tempb = 0

    temp = sys.stdin.readline().split(' ')
    for i in xrange(n):
        a[i] = int(temp[i])

    #print a
    le = int(sys.stdin.readline())

#finish reading data
    
    for i in range(le):
        maxe += a[i]

    tempe = maxe
    e[le-1] = maxe
    
    for i in xrange(le, n):
        tempe = tempe + a[i] - a[i - le]
        maxe = max(maxe, tempe)
        e[i] = maxe

    for i in xrange(n-1, n-1-le, -1):
        maxb += a[i]

    tempb = maxb
    b[n-le] = maxb
    
    for i in xrange(n-1-le, -1, -1):
        tempb = tempb + a[i] - a[i + le]
        maxb = max(maxb, tempb)
        b[i] = maxb

    for i in xrange(le):
        sumb[0] += a[i]

    for i in xrange(1, n - le + 1):
        sumb[i] = sumb[i-1] - a[i-1] + a[i+le-1]

    #print e
    #print b
    #print sumb
    ans = 0
    for i in xrange(le, n - 2*le +1):
        ans = max(ans, e[i-1] + sumb[i] + b[i+le])
        #print ans
        
    print ans
