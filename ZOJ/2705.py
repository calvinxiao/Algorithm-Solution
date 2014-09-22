#Problem ID: 2705
#Submit Time: 2012-08-30 10:50:38
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

lst = []
while 1:
    line = getline()
    if not line:
        break
    m, n = [int(num) for num in line.split()]
    getline()
    ans = 0
    temp = 0
    a = b = 1
    while a + b <= m:
        temp += a
        if m % (a + b) == 0:
            div = m / (a + b)
            ans = max(ans, temp * div * n)
            #print a, b, ans
        a, b = b, a + b
    a = b = 1
    temp = 0
    while a + b <= n:
        temp += a
        #print a, b, temp, temp, temp
        if n % (a + b) == 0:
            if n % (a + b) == 0:
                div = n / (a + b)
                ans = max(ans, temp * div * m)
                #print a, b, temp, ans
        a, b = b, a + b
    lst.append(ans)
for i in xrange(len(lst)):
    print lst[i]
    print ''
    

    
