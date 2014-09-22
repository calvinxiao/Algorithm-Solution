#Problem ID: 1342
#Submit Time: 2013-03-07 11:22:39
#Run Time: 740
#Run Memory: 13848
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

s = list('abcdefghijklmnopqrstuvwxyz')
d = {}
for i in xrange(len(s)):
    d[s[i]] = i
words = []
for word in s:
    words.append(word)
cur = 0
for ii in xrange(5):
    end = len(words)
    words2 = []
    for i in xrange(cur, end):
        j = d[words[i][0]]
        for k in xrange(j):
            words2.append(s[k] + words[i])
    words2.sort()
    for word in words2:
        words.append(word)
    cur = end
#words.sort()
total = len(words) - 1
#print words[83680]
while 1:
    line = getline().strip()
    if not line:
        break
    idx = -1
    l, r = 0, total
    ll = len(line)
    while l <= r:
        mid = (l+r)>>1
        lw = len(words[mid])
        if words[mid] == line:
            idx = mid
            break
        if lw < ll or (lw == ll and words[mid] < line):
            #print 'l', words[mid], line
            l = mid + 1
        else:
            #print 'r', words[mid], line
            r = mid - 1
    print idx+1
    
