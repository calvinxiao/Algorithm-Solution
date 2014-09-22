#Problem ID: 2345
#Submit Time: 2012-09-14 14:56:40
#Run Time: 20
#Run Memory: 452
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

ans = [0 for i in xrange(10001)]
rep = 1
day = 1
money = 1
total = 0
while 1:
    for i in xrange(rep):
        total += money
        ans[day] = total
        day += 1
        if day == 10001:
            break
    if day == 10001:
        break
    rep += 1
    money += 1
    

TC = getint()

for tc in xrange(TC):
    getline()
    if tc != 0:
        print ''
    while 1:
        n = getint()
        if not n:
            break
        print n, ans[n]
