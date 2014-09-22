#Problem ID: 2613
#Submit Time: 2012-08-31 10:46:57
#Run Time: 930
#Run Memory: 9396
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

tc = 0
TC = getint()
while tc < TC:
    tc += 1
    getline()
    ul, m = [int(num) for num in getlist()]
    u = []
    s1 = {}
    sn = {}
    for i in xrange(m):
        name, price = getlist()
        price = int(price)

        u.append([name, price])
        if not price in s1:
            s1[price] = 0
        if not price in sn:
            sn[price] = 0
        if not sn[price] == 0:
            if not s1[price] == 0:
                s1[price] += 1
            else:
                sn[price] += 1
                s1[price] = 0
        else:
            sn[price] += 1
        
    flag = False
    #print s1
    for key in s1:
        if s1[key] == 1:
            flag = True
            for i in xrange(m):
                if u[i][1] == key:
                    ansname = u[i][0]
                    ansprice = key
                    break
            break
    if not flag:
        MINB = 9999999
        MINP = 0
        for key in sn:
            if MINB > sn[key]:
                MINB = sn[key]
                MINP = key
        for i in xrange(m):
            if u[i][1] == MINP:
                ansname = u[i][0]
                ansprice = MINP
                break
    
    if tc != 1:
        print ''
    print 'Case %d:\nThe winner is %s.\nThe price is %d.' % (tc, ansname, ansprice)
    
