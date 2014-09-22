#Problem ID: 3479
#Submit Time: 2012-06-01 15:45:21
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

ans = ['Rat', 'Ox', 'Tiger', 'Rabbit', 'Dragon', 'Snake', 'Horse', 'Ram', 'Monkey', 'Rooster', 'Dog', 'Pig']

case = int(sys.stdin.readline())
while case>0:
  case -= 1
  n = int(sys.stdin.readline())
  print ans[(4 - n)%12]
