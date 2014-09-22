#Problem ID: 2358
#Submit Time: 2012-09-14 16:05:07
#Run Time: 140
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

s = set([1])
L = [362880, 40320, 1, 2, 5040, 6, 720, 120, 24]

for num in L:
    temp = []
    for sn in s:
        temp.append(sn + num)
    for tn in temp:
        s.add(tn)
    s.add(num)

while 1:
    n = getint()
    if n < 0:
        break
    if n in s:
        print 'YES'
    else:
        print 'NO'
