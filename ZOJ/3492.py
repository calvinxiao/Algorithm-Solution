#Problem ID: 3492
#Submit Time: 2012-11-11 18:51:14
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

#sys.stdin = open("a.txt","r")
TC = int(sys.stdin.readline())
for tc in xrange(TC):
    line = sys.stdin.readline().strip().split()
    n = int(line[0])
    name = line[1]
    lst = sys.stdin.readline().strip().split()
    idx = 0
    for i in xrange(n):
        if lst[i] == name:
            idx = i
            break
    print lst[(idx + n / 2) % n]
