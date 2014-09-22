#Problem ID: 3322
#Submit Time: 2013-04-23 09:27:45
#Run Time: 40
#Run Memory: 320
#ZOJ User: calvinxiao

tc = input()
while tc:
    tc -= 1
    a, b, c, aa, bb, cc = map(int, raw_input().split())
    ans = 0
    if a > aa:
        ans = 1
    elif a < aa:
        ans = 2
    else:
        if b > bb:
            ans = 1
        elif b < bb:
            ans = 2
        else:
            if c > cc:
                ans = 1
            elif c < cc:
                ans = 2
    if ans == 1:
        print 'cpcs'
    elif ans == 2:
        print 'javaman'
    else:
        print 'same'