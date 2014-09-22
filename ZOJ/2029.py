#Problem ID: 2029
#Submit Time: 2012-11-21 15:38:49
#Run Time: 0
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getints():
	return [int(num) for num in getlist()]

def getlist():
    return sys.stdin.readline().strip().split()

#sys.stdin = open("0.in", "r")

while 1:
    line = getline()
    if not line:
        break
    n, m = [int(num) for num in line.split()]
    a = getints()
    b = getints()
    a.sort()
    for num in b:
        if num < a[0] or num >= a[n-1]:
            print 'no such interval'
        else:
            l = 0
            r = n - 1
            while l + 1 < r:
                mid = l + (r - l) / 2
                if num < a[mid]:
                    r = mid
                else:
                    l = mid
            print '[%d,%d)' % (a[l], a[l+1])
    print ''
    