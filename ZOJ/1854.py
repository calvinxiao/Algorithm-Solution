#Problem ID: 1854
#Submit Time: 2012-09-06 17:47:48
#Run Time: 40
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    line = getline()
    if not line:
        break
    n = int(line)
    party = {}
    ans = {}
    for i in xrange(n):
        name = getline().strip()
        p = getline().strip()
        party[name] = p
        ans[name] = 0
    m = getint()
    for i in xrange(m):
        name = getline().strip()
        if name in ans:
            ans[name] += 1
    cnt = 0
    MAX = -1
    MAXname = ''
    for name in ans:
        if ans[name] > MAX:
            MAX = ans[name]
            MAXname = name
            cnt = 1
        elif ans[name] == MAX:
            cnt = 2
    if cnt == 2:
        print 'tie'
    else:
        print party[MAXname]
        
