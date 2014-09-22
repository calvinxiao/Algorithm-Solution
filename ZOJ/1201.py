#Problem ID: 1201
#Submit Time: 2012-08-30 23:56:16
#Run Time: 20
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    n = getint()
    if not n:
        break
    a = getlist()
    if a[0] == 'P':
        ans = [0 for i in xrange(n)]
        for i in xrange(1, n + 1):
            j = 1
            while int(a[j]) != i:
                if int(a[j]) > i:
                    ans[i-1] += 1
                j += 1
        print ' '.join([str(num) for num in ans])
    else:
        ans = [n]
        for i in xrange(n - 1, 0, -1):
            ans.insert(int(a[i]), i)
        print ' '.join([str(num) for num in ans])
    
