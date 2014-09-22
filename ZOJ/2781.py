#Problem ID: 2781
#Submit Time: 2012-05-24 10:44:41
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

t = int(sys.stdin.readline())
for tt in range(t):
    n = int(sys.stdin.readline())

    if n < 10:
        print n
        continue

    ten = 1
    half = 0
    while not n / (ten * 10) == 0:
        ten *= 10
        half = half * 10 + 4

    if n - (n / ten) * ten >= half + 1:
        print (n / ten + 1) * ten
    else:
        print n / ten * ten
