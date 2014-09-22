#Problem ID: 2829
#Submit Time: 2012-08-15 17:46:16
#Run Time: 260
#Run Memory: 2096
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

ans = [3, 5]
a = 3
b = 5
MAX = 100001
cnt = 2
while cnt < MAX:
    if a < b:
        if a + 3 == b:
            a += 6
        else:
            a += 3
        ans.append(a)
    else:
        if b + 5 == a:
            b += 10
        else:
            b += 5
        ans.append(b)
    cnt += 1

ans.sort()

while 1:
    line = getline()
    if not line:
        break
    print ans[int(line)-1]

