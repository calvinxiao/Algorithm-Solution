#Problem ID: 2099
#Submit Time: 2013-06-15 23:41:17
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

while 1:
    x, y = map(int, raw_input().split())
    if not x and not y:
        break
    xx, yy = [x], [y]
    while 1:
        x, y = map(int, raw_input().split())
        if not x and not y:
            break
        xx.append(x)
        yy.append(y)
    print '%d %d %d %d' % (min(xx), min(yy), max(xx), max(yy))
