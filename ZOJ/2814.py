#Problem ID: 2814
#Submit Time: 2012-05-26 20:25:00
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

while True:
    s = sys.stdin.readline().strip('\n')
    #print s
    if s == '*' or s == '':
        break

    n = len(s)

    suprise = True
    
    for i in xrange(n-1):
        m = {}
        for j in xrange(n - i - 1):
            substr = s[j] + s[j+i+1]
            if substr in m:
                suprise = False
                break
            m[substr] = 1

    if suprise:
         print s+' is surprising.'
    else:
         print s+' is NOT surprising.'
