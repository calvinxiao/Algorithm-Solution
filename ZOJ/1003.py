#Problem ID: 1003
#Submit Time: 2014-04-18 22:53:24
#Run Time: 110
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

def dfs(a, b, n):
    if  a == 1 and b == 1:
        return 1
    if n == 1:
        return 0
    good = 0
    if a % n == 0:
        good = dfs(a/n, b, n-1)
    if good:
        return good
    if b % n == 0:
        good = dfs(a, b/n, n-1)
    if good:
        return good
    good = dfs(a, b, n-1)
    return good

def main():
    while 1:
        line = getline().strip()
        if not line or len(line) == 0:
            break
        a, b = map(int, line.split())
        if a < b:
            a, b = b, a
        if not dfs(1, b, 100) or dfs(a, b, 100):
            print a
        else:
            print b

if __name__ == '__main__':
    main()

