#Problem ID: 2482
#Submit Time: 2012-08-13 16:32:45
#Run Time: 10
#Run Memory: 420
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

cases = getint()
for case in xrange(cases):
    s = getline().strip()
    ans = []
    for i in xrange(4):
        num = 256
        tempAns = 0
        for j in xrange(i * 8, i * 8 + 8):
            num /= 2
            if s[j] == '1':
                tempAns += num
        ans.append(str(tempAns))
    print '.'.join(ans)
    
