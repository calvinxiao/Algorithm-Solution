#Problem ID: 2736
#Submit Time: 2012-06-04 16:28:10
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

while True:
    line = sys.stdin.readline()
    if not line:
        break;
    num = int(line)
    n = num
    t = 0
    while n>0:
        t += (n%10)*(n%10)*(n%10)
        n /= 10
    if t == num:
        print 'Yes'
    else:
        print 'No'

    
