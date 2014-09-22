#Problem ID: 1100
#Submit Time: 2012-06-13 15:28:55
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import math
import sys

while True:
    line = sys.stdin.readline()
    line = line.split(' ')
    h = int(line[0])
    w = int(line[1])

    if h==0 and w==0:
        break
    
    if h*w%2 == 1:
        print 0
        continue

    ans = 1.0
    for i in xrange(1, h/2+1):
        for j in xrange(1, w/2+1):
            ans *= 4 * (math.cos(math.pi*i/(h+1.0)) ** 2 + math.cos(math.pi*j/(w+1.0)) ** 2)

    print '%.0f' % ans
