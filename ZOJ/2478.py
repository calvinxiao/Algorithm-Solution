#Problem ID: 2478
#Submit Time: 2012-08-13 16:15:26
#Run Time: 10
#Run Memory: 320
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
    cnt = 1
    pre = s[0]
    for i in xrange(1, len(s)):
        if s[i] == pre:
            cnt += 1
        else:
            if cnt != 1:
                sys.stdout.write(str(cnt))
            sys.stdout.write(pre)
            cnt = 1
            pre = s[i]
    if cnt != 1:
        sys.stdout.write(str(cnt))
    print s[len(s) - 1]

    

    
