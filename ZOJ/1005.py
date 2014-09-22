#Problem ID: 1005
#Submit Time: 2014-04-22 11:22:58
#Run Time: 0
#Run Memory: 272
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

def dfs(a, b, A, B, N, ans, s):
    #print a, b, A, B, N, ans
    if a + b * 10000 in s:
        return False
    s.add(a + b * 10000)
    if a == N or b == N:
        ans.append('success')
        return True
    if a != A:
        if dfs(A, b, A, B, N, ans, s):
            ans.append('fill A')
            return True
    if b != B:
        if dfs(a, B, A, B, N, ans, s):
            ans.append('fill B')
            return True
    if a != 0 and b != B:
        t = min(a, B - b)
        if dfs(a - t, b + t, A, B, N, ans, s):
            ans.append('pour A B')
            return True
    if a != A and b != 0:
        t = min(A - a, b)
        if dfs(a + t, b - t, A, B, N, ans, s):
            ans.append('pour B A')
            return True
    if a != 0:
        if dfs(0, b, A, B, N, ans, s):
            ans.append('empty A')
            return True
    if b != 0:
        if dfs(a, 0, A, B, N, ans, s):
            ans.append('empty B')
            return True
    return False  

def main():
    while 1:
        line = getline()
        if not line:
            break
        A, B, N = map(int, line.split())
        ans = []
        s = set([])
        dfs(0, 0, A, B, N, ans, s)
        ans.reverse()
        for s in ans:
            print s

if __name__ == '__main__':
    main()
