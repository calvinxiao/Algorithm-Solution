#Problem ID: 2807
#Submit Time: 2012-05-24 12:00:33
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

t = int(sys.stdin.readline())
for tt in range(t):
    lst = sys.stdin.readline().split(' ')
    s = 0
    for i in range(len(lst)):
        s += int(lst[i])
    s -= int(lst[0])*2
    s += 1
    print s


    
