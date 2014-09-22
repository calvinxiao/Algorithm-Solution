#Problem ID: 1828
#Submit Time: 2012-09-06 01:22:29
#Run Time: 20
#Run Memory: 1428
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

f = [0 for i in xrange(4880)]
f[1] = 1
f[2] = 1
i = 3
while i < 4880:
    f[i] = f[i-1] + f[i-2]
    i += 1
        
while 1:
    line = getline()
    if not line:
        break
    print f[int(line)]
    

    
