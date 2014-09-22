#Problem ID: 2932
#Submit Time: 2012-05-24 11:42:42
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

d = {}
d[' '] = '%20'
d['!'] = '%21'
d['$'] = '%24'
d['%'] = '%25'
d['('] = '%28'
d[')'] = '%29'
d['*'] = '%2a'


while True:
    line=sys.stdin.readline().strip('\n')
    if line == '#':
        break
    ans = ''
    for i in range(len(line)):
        if line[i] in d:
            ans += d[line[i]]
        else:
            ans += line[i]
    print ans

