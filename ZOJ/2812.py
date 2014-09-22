#Problem ID: 2812
#Submit Time: 2012-08-09 14:40:07
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

v = {}
v[' '] = 0
s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
for i in xrange(len(s)):
    v[s[i]] = i + 1

while True:
    line = getline().rstrip()
    if line == '#':
        break
    ans = 0
    for i in xrange(len(line)):
        ans += (i + 1) * v[line[i]]
    print ans
    
