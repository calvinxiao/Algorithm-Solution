#Problem ID: 1115
#Submit Time: 2012-08-16 00:49:47
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys
 
def todo(n):
    if n < 10: 
        return n
    ans = 0 
    while n != 0:
        ans += n % 10
        n /= 10
    return todo(ans)

while 1:
    n = int(sys.stdin.readline())
    if not n:
        break
    print todo(n)  