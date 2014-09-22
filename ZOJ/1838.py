#Problem ID: 1838
#Submit Time: 2014-07-08 15:19:01
#Run Time: 10
#Run Memory: 140
#ZOJ User: calvinxiao

import sys

#sys.stdin = open("0.in", "r")

def solve(l):
    s = "the quick brown fox jumps over the lazy dog\n"
    n = len(s)
    d = {}
    able = 0
    for line in l:
        if able:
            break
        if n == len(line):
            d = {}
            able = 1
            good = 1
            for i in xrange(n):
                if line[i] == ' ' and s[i] != ' ':
                    good = 0
                    break
                elif line[i] != ' ' and s[i] == ' ':
                    good = 0
                    break
            if not good:
                able = 0
                continue
            for i in xrange(n):
                if line[i] not in d:
                    d[line[i]] = s[i]
                else:
                    if s[i] != d[line[i]]:
                        able = 0
                        break

    if not able:
        print 'No solution.'
    else:
        for line in l:
            for c in line:
                if c in d:
                    sys.stdout.write(d[c])
                else:
                    sys.stdout.write(c)

tc = 0
l = []
for line in sys.stdin:
    if line == '\n':
        if tc:
            print ''
        tc += 1
        solve(l)
        l = []
    else:
        l.append(line)
if l:
    if tc:
        print ''
    tc += 1
    solve(l)
