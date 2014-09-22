#Problem ID: 1745
#Submit Time: 2013-07-22 15:32:01
#Run Time: 20
#Run Memory: 320
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
#sys.stdout = open("0.in", "w")
tc = 0
while 1:
    a = getints()
    if a[0] == 5280:
        break
    if tc:
        print ''
    tc += 1
    d = a[0]
    a[0] = 0
    for i in xrange(1, len(a)):
        s, t = a[i-1] - d, a[i] - d
        if s < 0:
            s = -s
        if t < 0:
            t = -t;
        print 'Moving from %d to %d:' % (a[i-1], a[i]),
        if a[i] == d:
            print 'found it!'
            break
        if s < t:
            print 'colder.'
        elif s > t:
            print 'warmer.'
        else:
            print 'same.'
