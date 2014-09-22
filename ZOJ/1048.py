#Problem ID: 1048
#Submit Time: 2012-05-24 17:13:24
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

s = 0.0
for i in range(12):
    t = float(sys.stdin.readline())
    s += t
print '$%0.2f' % (s/12.0)

    
