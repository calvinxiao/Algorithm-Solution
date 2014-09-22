#Problem ID: 2417
#Submit Time: 2012-08-13 16:05:37
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

while 1:
    n = getint()
    if not n:
        break
    ans = 1
    while n % 2 == 0:
        ans *= 2
        n /= 2
    print ans
    

    
