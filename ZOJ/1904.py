#Problem ID: 1904
#Submit Time: 2012-08-08 22:29:47
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

from math import *
import sys

D, V = [int(num) for num in sys.stdin.readline().split()]

while D != 0 and V != 0:
    d = pow(1.0 * D * D * D - 6.0 * V / 3.141592657, 0.333333333333)
    print '%.3f' % d
    D, V = [int(num) for num in sys.stdin.readline().split()]
