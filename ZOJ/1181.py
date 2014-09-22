#Problem ID: 1181
#Submit Time: 2012-05-31 01:01:16
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

from sys import stdin

d = {}

while True:
    line = stdin.readline().strip('\n')
    if line == 'XXXXXX':
        break
    else:
        l = list(line)
        l.sort()
        key = ''.join(l)
        if not key in d:
            d[key] = []
        d[key].append(line)

while True:
    line = stdin.readline().strip('\n')
    if line == 'XXXXXX':
        break
    else:
        l = list(line)
        l.sort()
        key = ''.join(l)
        if not key in d:
            print 'NOT A VALID WORD'
        else:
            d[key].sort()
            for i in xrange(0, len(d[key])):
                print d[key][i]
        print '******'
    

