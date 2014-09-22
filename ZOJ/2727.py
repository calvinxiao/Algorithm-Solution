#Problem ID: 2727
#Submit Time: 2012-08-20 02:12:32
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys
case = 0
while 1:
    line = sys.stdin.readline()
    n = int(line)
    if not n:
        break
    if case != 0:
        print ''
    case += 1
    ans = []
    for i in xrange(n):
        ans.append(sys.stdin.readline().rstrip().split())
        ans[i][1] = int(ans[i][1])
        ans[i][2] = int(ans[i][2])
    ans.sort(key = lambda s:s[2])
    ans.sort(key = lambda s:s[1])
    ans.sort(key = lambda s:s[0])
    criteria = sys.stdin.readline().strip()
    if criteria == 'Year':
        ans.sort(key = lambda s:s[1])
    elif criteria == 'Price':
        ans.sort(key = lambda s:s[2])
    for i in xrange(n):
        print ' '.join([str(num) for num in ans[i]])
