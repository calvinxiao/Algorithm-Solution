#Problem ID: 2773
#Submit Time: 2012-06-04 16:36:57
#Run Time: 90
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

n = int(sys.stdin.readline())
a = []
for i in xrange(n):
    a.append(int(sys.stdin.readline()))

for i in xrange(1, n+1):
    sys.stdout.write(str(i) +' ' + str(a[i-1]) + ' ')
    ans = 0
    for j in xrange(1, a[i-1] + 1):
        ans += j*(j+1)*(j+2)/2
    print ans
