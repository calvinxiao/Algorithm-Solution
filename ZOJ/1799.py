#Problem ID: 1799
#Submit Time: 2013-03-09 19:06:56
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

while 1:
    key = raw_input()
    if key == "THEEND":
        break
    cypher = raw_input()
    se = list(set(list(key)))
    se.sort()
    m = len(key)
    n = len(cypher) / m
    ori = [['' for j in xrange(m)] for i in xrange(n)]
    idx = 0
    for c in se:
        #print c
        for j in xrange(m):
            if key[j] == c:
                for i in xrange(n):
                    ori[i][j] = cypher[idx]
                    idx+=1
    ans = ''
    for i in xrange(n):
        ans += ''.join(ori[i])
    print ans
