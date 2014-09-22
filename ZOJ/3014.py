#Problem ID: 3014
#Submit Time: 2012-08-30 17:03:06
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

def isprime(n):
    sn = pow(n, 0.5)
    for i in xrange(2,int(sn) + 1):
        if n % i == 0:
            return False
    return True
    
digit = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']

ans = [0,0,0,7,13,23,1237,1933,32089,456697,9875321,17343437,61405650457,9641919691,4025602087193,129084354574697,4483583611130929]


while 1:
    char = getline()
    if not char:
        break
    char = char.strip()
    if char == 'A':
        n = 11
    elif char == 'B':
        n = 12
    elif char == 'C':
        n = 13
    elif char == 'D':
        n = 14
    elif char == 'E':
        n = 15
    elif char == 'F':
        n = 16
    else:
        n = int(char)
    
    if ans[n] == 0:
        print 'not special'
    else:
        a = ans[n]
        s = []
        while a:
            s.append(digit[a%n])
            a /= n
        s.reverse()
        print ''.join(s)
    
