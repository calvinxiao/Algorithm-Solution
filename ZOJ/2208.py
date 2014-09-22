#Problem ID: 2208
#Submit Time: 2012-06-01 23:23:21
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys
while True:
  c = int(sys.stdin.readline())
  if c==0:
    break
  text = sys.stdin.readline().strip('\n')

  r = len(text)/c
  
  l = 0
  for j in xrange(c): 
    for i in xrange(r):
      if i%2 == 0:
        sys.stdout.write(text[i * c + l])
      else:
        sys.stdout.write(text[i * c + c - 1 - l])
    l += 1

  
  print ''
  
