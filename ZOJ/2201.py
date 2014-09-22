#Problem ID: 2201
#Submit Time: 2012-06-01 22:31:11
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

n = int(sys.stdin.readline())

while n:
  n -= 1
  a = sys.stdin.readline().split(' ')
  if int(a[0]) >= int(a[1]):
    print 'MMM BRAINS'
  else:
    print 'NO BRAINS'
