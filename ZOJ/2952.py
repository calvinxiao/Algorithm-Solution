#Problem ID: 2952
#Submit Time: 2012-09-13 09:15:14
#Run Time: 260
#Run Memory: 2108
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

s = set([])
MAX = 2 ** 31
for i in xrange(2, 46341):
    j = i * i
    for k in xrange(30):
        if j >= MAX:
            break
        s.add(j)
        j *= i
a = [num for num in s]
a.sort()
for num in a:
    print num
        

    
