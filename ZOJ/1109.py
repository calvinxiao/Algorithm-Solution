#Problem ID: 1109
#Submit Time: 2012-05-24 11:33:54
#Run Time: 770
#Run Memory: 12008
#ZOJ User: calvinxiao

import sys

d = {}

while True:
    line=sys.stdin.readline().strip('\n')
    if line == '':
        break
    sp = line.split(' ')
    d[sp[1]]=sp[0]

while True:
    line=sys.stdin.readline().strip('\n')
    if line == '':
        break
    if line in d:
        print d[line]
    else:
        print 'eh'
    
