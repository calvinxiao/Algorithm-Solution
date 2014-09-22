#Problem ID: 2791
#Submit Time: 2012-09-21 17:06:51
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

#sys.stdin = open("a.txt","r")
r = sys.stdin
d = {}
d['m'] = 1000
d['c'] = 100
d['x'] = 10
d['i'] = 1


def gao1(s):
    t = 0
    num = 0
    for c in s:
        if c in d:
            if t == 0:
                num += d[c]
            else:
                num += t * d[c]
            t = 0
        else:
            t *= 10
            t += ord(c) - ord('0')
    return num

def gao2(num):
    s = []
    if num >= 1000:
        t = num / 1000
        num %= 1000
        if t == 1:
            s.append('m')
        elif t != 0:
            s.append(str(t) + 'm')
    if num >= 100:
        t = num / 100
        num %= 100
        if t == 1:
            s.append('c')
        elif t != 0:
            s.append(str(t) + 'c')
    if num >= 10:
        t = num / 10
        num %= 10
        if t == 1:
            s.append('x')
        elif t != 0:
            s.append(str(t) + 'x')
            
    if num == 1:
        s.append('i')
    elif num != 0:
        s.append(str(num) + 'i')
        
    return ''.join(s)

T = int(r.readline())
while T:
    T -= 1
    a, b = r.readline().strip().split()
    print gao2(gao1(a) + gao1(b))

