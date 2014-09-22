#Problem ID: 1494
#Submit Time: 2012-08-19 04:31:46
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getints():
    return [int(num) for num in getlist()]

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    n, u, d = getints()
    if n == 0:
        break
    ans = 0
    if n <= u:
        ans = 1
    else:
        ans = (n - u) / (u - d) * 2 + 1
        if (n - u) % (u - d) != 0:
            ans += 2
    print ans
