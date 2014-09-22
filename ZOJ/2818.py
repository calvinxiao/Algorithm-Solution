#Problem ID: 2818
#Submit Time: 2012-08-15 18:11:20
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys
from math import *

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    B, N = [int(num) for num in getlist()]
    if B == 0:
        break

    A = pow(B, 1.0/ N)
    A1 = pow(floor(A), N)
    A2 = pow(ceil(A),N)
    #print A, A1, A2
    
    if B - A1 > A2 - B:
        print int(ceil(A))
    else:
        print int(floor(A))


