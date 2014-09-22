#Problem ID: 1954
#Submit Time: 2014-01-12 12:44:12
#Run Time: 330
#Run Memory: 272
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline().strip()

def getint():
    return int(getline())

def getints():
    return [int(num) for num in getline().split()]

a = []
ans = {}
while 1:
    l = getline()
    if not l:
        break
    a.append(int(l))

ans[1] = [0,0]
ans[2] = [0,1]
I = 2
V = [0,1]
for step in xrange(1, 90):
    for i in xrange(step):
        V = [V[0] - 1, V[1] + 0]
        I += 1
        if I in a:
            ans[I] = [V[0], V[1]]
    for i in xrange(step):
        V = [V[0] - 0, V[1] - 1]
        I += 1
        if I in a:
            ans[I] = [V[0], V[1]]
    for i in xrange(step):
        V = [V[0] + 1, V[1] - 1]
        I += 1
        if I in a:
            ans[I] = [V[0], V[1]]
    for i in xrange(step):
        V = [V[0] + 1, V[1] + 0]
        I += 1
        if I in a:
            ans[I] = [V[0], V[1]]
    for i in xrange(step + 1):
        V = [V[0] - 0, V[1] + 1]
        I += 1
        if I in a:
            ans[I] = [V[0], V[1]]
    for i in xrange(step):
        V = [V[0] - 1, V[1] + 1]
        I += 1
        if I in a:
            ans[I] = [V[0], V[1]]
for num in a:
    print ans[num][0], ans[num][1]

    
