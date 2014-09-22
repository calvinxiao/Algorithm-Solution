#Problem ID: 1016
#Submit Time: 2013-03-14 22:46:38
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return input()

def getints():
	return map(int, raw_input().split())

def getlist():
    return raw_input().split()

#sys.stdin = open("0.in", "r")


TC = getint()
while TC:
    TC -= 1
    n = getint()
    p = getints()
    a = []
    cnt = 0
    for num in p:
        while cnt < num:
            cnt += 1
            a.append(0)
        a.append(1)
    #print a
    ans = []
    for i in xrange(len(a)):
        if a[i] == 1:
            st = 0
            cnt = 0
            for j in xrange(i-1, -1, -1):
                if a[j]:
                    st += 1
                else:
                    cnt += 1
                    if st:
                        st -= 1
                    else:
                        ans.append(cnt)
                        break
    print ' '.join([str(num) for num in ans])
            
