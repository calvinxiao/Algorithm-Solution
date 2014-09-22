#Problem ID: 1831
#Submit Time: 2012-09-06 16:23:07
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()


ori = getline().strip()
sub = getline().strip()
d = {}
for i in xrange(len(ori)):
    d[ori[i]] = sub[i]

print sub
print ori
for line in sys.stdin:
    n = len(line)
    for c in line:
        if c in d:
            sys.stdout.write(d[c])
        else:
            sys.stdout.write(c)
