#Problem ID: 1205
#Submit Time: 2012-08-30 21:48:40
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

s = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l']

def PRINT(n):
    a = []
    while n:
        a.append(s[n % 20])
        n /= 20
    if len(a) == 0:
        a.append('0')
    a.reverse()
    print (''.join(a))
    
while 1:
    n1 = getline()
    if not n1:
        break
    n2 = getline()
    ans = int(n1, 20) + int(n2, 20)
    #print ans
    PRINT(ans)
