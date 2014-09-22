#Problem ID: 1073
#Submit Time: 2013-04-14 20:50:31
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

while 1:
    line = getline()
    if not line:
        break
    line = line.strip()
    ori = list(line)
    ori.sort()
    ori = ''.join(ori)
    n = len(line)
    a = int(line)
    good = True
    for i in xrange(2, n+1):
        b = a * i
        b = str(b)
        b = list(b)
        while len(b) < n:
            b.append('0')
        b.sort()
        b = ''.join(b)
        if ori != b:
            good = False
            break
    if good:
        print '%s is cyclic' % line
    else:
        print '%s is not cyclic' % line
