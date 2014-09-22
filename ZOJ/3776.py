#Problem ID: 3776
#Submit Time: 2014-05-16 10:52:07
#Run Time: 30
#Run Memory: 140
#ZOJ User: calvinxiao

tc = input()
while tc:
    tc -= 1
    n, m = map(int, raw_input().split())
    a = sum(map(int, raw_input().split()))
    b = sum(map(int, raw_input().split()))
    if a > b:
        print 'Calem'
    elif a < b:
        print 'Serena'
    else:
        print 'Draw'