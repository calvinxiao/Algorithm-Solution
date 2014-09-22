#Problem ID: 3019
#Submit Time: 2012-08-09 17:45:03
#Run Time: 540
#Run Memory: 1424
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while True:
    line = getline()
    if not line:
        break
    
    n, m = [int(num) for num in line.split()]

    a = [int(num) for num in getlist()]
    b = [int(num) for num in getlist()]
    a.sort()
    b.sort()
    i = 0
    j = 0
    ans = 0
    while i < n and j < m:
        if a[i] == b[j]:
            ans += 1
            i += 1
            j += 1
        elif a[i] < b[j]:
            i += 1
        else:
            j += 1
    print ans
