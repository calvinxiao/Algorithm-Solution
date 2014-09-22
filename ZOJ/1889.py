#Problem ID: 1889
#Submit Time: 2012-08-12 02:37:29
#Run Time: 580
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while True:
    L = getline()
    if not L:
        break
    n = int(L)
    cnt = 0
    a = 1
    b = 0
    while True:
        cnt += 1
        b += a
        if b % n == 0:
            break
        a *= 10
    print cnt

    
