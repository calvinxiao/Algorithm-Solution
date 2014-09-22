#Problem ID: 1225
#Submit Time: 2013-04-12 13:59:18
#Run Time: 10
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

def isnum(s):
    try:
        float(s)
        return True
    except:
        return False

while 1:
    line = raw_input()
    if line == ".":
        break
    line = line.split(', ')
    n = len(line)
    line[n-1] = line[n-1].replace(".", "")
    a = []
    b = []
    for s in line:
        if isnum(s):
            a.append(int(s))
        else:
            b.append(s)
    a.sort()
    m = len(b)
    for i in xrange(m):
        for j in xrange(i + 1, m):
            if b[i].lower() > b[j].lower():
                b[i], b[j] = b[j], b[i]

    ii, jj = 0, 0
    for i in xrange(n):
        if isnum(line[i]):
            line[i] = str(a[ii])
            ii += 1
        else:
            line[i] = b[jj]
            jj += 1
    print ', '.join(line) + '.'
    

            
