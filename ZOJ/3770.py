#Problem ID: 3770
#Submit Time: 2014-06-24 12:20:07
#Run Time: 170
#Run Memory: 916
#ZOJ User: calvinxiao


import sys

def getline():
    return sys.stdin.readline()

def getint():
    return input()

def getints():
	return map(int, raw_input().split())

def getlist():
    return raw_input().split()

#sys.stdin = open("0.in", "r")

tc = input()
while tc:
    tc -= 1
    n = input()
    a = []
    nn = 0
    for i in xrange(n):
        l = raw_input().split()
        b = i, int(l[0]), l[1], int(l[2])
        a.append([b, ''])
        if b[3] > 0:
            nn += 1
    a.sort(key = lambda x:x[0][1])
    a.sort(key = lambda x:x[0][2])
    a.sort(key = lambda x:x[0][3], reverse = True)

    lv6 = int(nn * 0.03)
    lv5 = int(nn * 0.07)
    lv4 = int(nn * 0.2)
    lv3 = int(nn * 0.3)
    for i in xrange(n):
        if lv6:
            a[i][1] = 'LV6'
            lv6 -= 1
        elif lv5:
            a[i][1] = 'LV5'
            lv5 -= 1
        elif lv4:
            a[i][1] = 'LV4'
            lv4 -= 1
        elif lv3:
            a[i][1] = 'LV3'
            lv3 -= 1
        elif a[i][0][3] != 0:
            a[i][1] = 'LV2'
        else:
            a[i][1] = 'LV1'
    a.sort()
    for b in a:
        print b[1]
