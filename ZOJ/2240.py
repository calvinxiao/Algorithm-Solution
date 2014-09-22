#Problem ID: 2240
#Submit Time: 2014-08-24 12:30:55
#Run Time: 20
#Run Memory: 140
#ZOJ User: calvinxiao

import sys

def f(s):
    if same(s):
        return str(len(s)) + s[0]
    else:
        s = ''.join(s)
        ret = s.replace('1', '11')
        return '1' + ret + '1'

def same(s):
    return len(s) > 1 and len(s) == s.count(s[0])

for line in sys.stdin:
    line = line.strip('\n')
    s = []
    ans = []
    n = len(line)
    for i, c in enumerate(line):
        if not s:
            s.append(c)
        elif not same(s) and s[-1] != c and not (i + 1 < n and line[i+1] == c):
            s.append(c)
        elif (len(s) == 1 or same(s)) and s[-1] == c:
            s.append(c)
        else:
            ans.append(f(s))
            s = [c]
        if same(s) and len(s) == 9:
            ans.append(f(s))
            s = []
    if s:
        ans.append(f(s))
    print ''.join(ans)