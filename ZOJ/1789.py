#Problem ID: 1789
#Submit Time: 2013-03-09 17:07:58
#Run Time: 280
#Run Memory: 2420
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
    n, m = getints()
    if n + m == 0:
        break
    st = [[] for i in xrange(n)]
    group = [[] for i in xrange(m)]
    vn = [False for i in xrange(n)]
    vm = [False for i in xrange(m)]
    for i in xrange(m):
        a = getints()
        for j in xrange(1, a[0] + 1):
            st[a[j]].append(i)
            group[i].append(a[j])
    vn[0] = True
    s = [0]
    while len(s):
        top = s.pop()
        vn[top] = True
        for i in xrange(len(st[top])):
            if not vm[st[top][i]]:
                vm[st[top][i]] = True
                for j in xrange(len(group[st[top][i]])):
                    if not vn[group[st[top][i]][j]]:
                        s.append(group[st[top][i]][j])
    ans = 0
    #print vn
    for i in xrange(n):
        if vn[i]:
            ans += 1
    print ans
