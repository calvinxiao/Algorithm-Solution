#Problem ID: 3207
#Submit Time: 2012-05-24 11:25:05
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

t = int(sys.stdin.readline())
a = []
for tt in range(t):
    name = sys.stdin.readline()
    a.append(name.strip('\n'))

#print a

k = int(sys.stdin.readline())
person = [0 for i in range(k)]

for kk in range(k):
    lst = sys.stdin.readline().split(' ')
    #print lst
    for i in range(1, len(lst)):
        if a.count(lst[i].strip('\n')) > 0:
            person[kk] += 1

for i in range(k):
    print person[i]
    

    
