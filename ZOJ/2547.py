#Problem ID: 2547
#Submit Time: 2012-06-01 10:53:00
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys
dp = [0 for i in xrange(31)]
dp[0] = 1
dp[2] = 3
for i in xrange(4, 31, 2):
  dp[i] = dp[i-2]*4 - dp[i-4]
  
while True:
  n = int(sys.stdin.readline())
  if n==-1:
    break
  print dp[n]
