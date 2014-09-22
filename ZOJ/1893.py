#Problem ID: 1893
#Submit Time: 2012-09-07 01:35:13
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
    line = getline()
    if not line:
        break
    n = int(line)
    if n < 10:
        print 'Stan wins.'
        continue

    win = 1
    L = n / 9
    if n % 9 != 0:
        L += 1
    #print L, win
    while L > 1:
        if win:
            newL = L / 2
            if L % 2 == 1:
                newL += 1
        else:
            newL = L / 9
            if L % 9 != 0:
                newL += 1
        L = newL
        win = (win + 1) % 2
        #print L, win
    if win:
        print 'Stan wins.'
    else:
        print 'Ollie wins.'
