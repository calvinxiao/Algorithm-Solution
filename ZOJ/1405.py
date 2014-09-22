#Problem ID: 1405
#Submit Time: 2012-08-19 15:25:55
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


while 1:
    line = getline().rstrip()
    if line[0] == '0':
        break
    cust = {}
    total, s = line.split()
    total = int(total)
    cnt = 0
    ans = 0
    for i in xrange(len(s)):
        if s[i] not in cust:
            cust[s[i]] = 0
        if cust[s[i]] == 0:
            if cnt < total:
                cnt += 1
                cust[s[i]] = 1
            else:
                ans += 1
                cust[s[i]] = 2
        elif cust[s[i]] == 1:
            cnt -= 1
            cust[s[i]] = 0
        elif cust[s[i]] == 2:
            cust[s[i]] = 0
    if ans == 0:
        print 'All customers tanned successfully.'
    else:
        print '%d customer(s) walked away.' % (ans)
