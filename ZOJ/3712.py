#Problem ID: 3712
#Submit Time: 2014-01-05 18:22:02
#Run Time: 0
#Run Memory: 140
#ZOJ User: calvinxiao

#import sys

#sys.stdin = open("0.in", "r")

T = input()

while T:
    T -= 1
    a, b, c = map(int, raw_input().split())
    sa = a * (2 * a - 2) / 2
    sb = b * (2 * (a + b) - 2 + 2 * a) / 2
    sc = c * (2 * (a + b + c) - 2 + 2 * (a + b)) / 2 
    MIN = 300 * (a + sa) + 100 * (b + sb) + 50 * (c + sc)
    
    sc = c * (2 * c - 2) / 2
    sb = b * (2 * (c + b) - 2 + 2 * c) / 2
    sa = a * (2 * (a + b + c) - 2 + 2 * (c + b)) / 2 
    MAX = 300 * (a + sa) + 100 * (b + sb) + 50 * (c + sc)

    print MIN, MAX
