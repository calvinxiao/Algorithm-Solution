#Problem ID: 2371
#Submit Time: 2014-01-03 23:23:18
#Run Time: 10
#Run Memory: 140
#ZOJ User: calvinxiao


#import sys

#sys.stdin = open("0.in", "r")

a = []
three = 1
for i in xrange(77):
    a.append(three)
    three = three *3

while 2:
    n = input()
    if n == 0:
        break
    n -= 1
    if n == 0:
        print '{ }'
        continue
    ans = []
    for i in xrange(77):
        if (1 << i) & n:
            ans.append(a[i])
    print '{ %s }' % (', '.join([str(num) for num in ans]))
