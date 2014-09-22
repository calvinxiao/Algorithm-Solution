#Problem ID: 3328
#Submit Time: 2013-05-22 23:07:29
#Run Time: 330
#Run Memory: 320
#ZOJ User: calvinxiao

while 1:
    n = input()
    if not n:
        break
    print (n-1)/2 + (n - 1 & 1)
