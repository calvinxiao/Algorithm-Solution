#Problem ID: 3406
#Submit Time: 2013-03-21 22:10:03
#Run Time: 920
#Run Memory: 2588
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

a = list(sys.stdin.read())
n = len(a)
i, j = 0, 0
while i < n:
    cnt = 0
    while i < len(a) and not a[i].isalpha():
        i += 1
    j = i + 1
    while j < len(a) and a[j].isalpha():
        j += 1
    cnt = j - i - 2
    if cnt > 0:
        a[i+1] = str(cnt)
        a[i+2:j-1] = ['-1'] * (j-i-3)
        i += 3
    i = j + 1
for c in a:
    if c != '-1':
        sys.stdout.write(c)

            
