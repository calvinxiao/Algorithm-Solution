#Problem ID: 1061
#Submit Time: 2012-09-19 01:07:51
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

def solve():
    now = 'http://www.acm.org/'
    back = []
    forward = []
    while 1:
        cmd = getlist()
        if cmd[0] == 'VISIT':
            back.append(now)
            now = cmd[1]
            print now
            forward = []
            
        elif cmd[0] == 'BACK':
            if not len(back):
                print 'Ignored'
            else:
                forward.append(now)
                now = back.pop()
                print now
                
        elif cmd[0] == 'FORWARD':
            if not len(forward):
                print 'Ignored'
            else:
                back.append(now)
                now = forward.pop()
                print now
                
        elif cmd[0] == 'QUIT':
            break


TC = getint()
for tc in xrange(TC):
    getline()
    if tc:
        print ''
    solve()



    
