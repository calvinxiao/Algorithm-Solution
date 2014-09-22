#Problem ID: 1056
#Submit Time: 2013-03-15 16:57:51
#Run Time: 10
#Run Memory: 320
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

while 1:
    n = getint()
    if not n: break
    s = raw_input()
    w = [[25, i] for i in xrange(30, 10, -1)]
    ans = 0
    status = 0
    for i in xrange(n):
        del w[19]
        ans = i + 1
        x, y = w[0][0], w[0][1]
        nx, ny = 0, 0
        if s[i] == 'N':
            x -= 1
        elif s[i] == 'E':
            y += 1
        elif s[i] == 'S':
            x += 1
        elif s[i] == 'W':
            y -= 1
        #print ans, s[i], x, y, w
        if [x, y] in w:
            status = 1
            break
        if x < 1 or x > 50 or y < 1 or y > 50:
            status = 2
            break
        w.insert(0, [x, y])
    if status == 0:
        print 'The worm successfully made all %d moves.' % ans
    elif status == 1:
        print 'The worm ran into itself on move %d.' % ans
    else:
        print 'The worm ran off the board on move %d.' % ans
            
