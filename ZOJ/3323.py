#Problem ID: 3323
#Submit Time: 2013-04-23 09:30:32
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

tc = input()
digit = '0123456789'
while tc:
    tc -= 1
    a = raw_input()
    ans = []
    for c in a:
        if not c in digit:
            ans.append(c)
    print ''.join(ans)