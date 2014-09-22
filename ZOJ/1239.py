#Problem ID: 1239
#Submit Time: 2014-01-05 18:33:29
#Run Time: 10
#Run Memory: 140
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
'''
def doit(n):
    M = 1
    a = [0 for i in xrange(n)]
    good = 1
    while good:
        good = 0
        for i in xrange(n):
            if int(int((a[i] + M + 0.01) ** 0.5) ** 2) == a[i] + M:
                a[i] = M
                M += 1
                good = 1
                break
                print i, a[i]
            elif not a[i]:
                a[i] = M
                M += 1
                good = 1
                break
                print i, a[i]
            
        #print a, good, M
    return M - 1

ans = []
for i in xrange(1, 51):
    ans.append(doit(i))
print ans
'''
tc = input()
ans = [1, 3, 7, 11, 17, 23, 31, 39, 49, 59, 71, 83, 97, 111, 127, 143, 161, 179, 199, 219, 241, 263, 287, 311, 337, 363, 391, 419, 449, 479, 511, 543, 577, 611, 647, 683, 721, 759, 799, 839, 881, 923, 967, 1011, 1057, 1103, 1151, 1199, 1249, 1299]
for i in xrange(tc):
    n = input()
    print ans[n-1]
#print doit(25)
#for i in xrange(1, 50):
#    print i, doit(i)