#Problem ID: 2722
#Submit Time: 2012-09-14 10:11:35
#Run Time: 40
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    n = getint()
    ans = 0
    if not n:
        break
    while n != 1:
        ans += 1
        n = n / 2 + n % 2
    print ans

    
