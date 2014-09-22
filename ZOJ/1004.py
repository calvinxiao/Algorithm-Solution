#Problem ID: 1004
#Submit Time: 2014-04-18 23:41:15
#Run Time: 0
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

def dfs(s, t, cur, stack, ans, k):
    #print s, t, cur, stack, ans, k
    for i in xrange(len(cur)):
        if cur[i] != t[i]:
            return
    if k == len(t) * 2:
        if cur == t:
            print ' '.join(ans), ''
        return

    if len(s) != 0:
        ans[k] = 'i'
        stack.append(s[0])
        ss = s[1:]
        dfs(ss, t, cur, stack, ans, k + 1)
        stack.pop()
    if len(stack) != 0:
        ans[k] = 'o'
        c = stack.pop()
        cur = cur + c
        dfs(s, t, cur, stack, ans, k + 1)
        stack.append(c)

def main():
    while 1:
        s = getline().strip()
        t = getline().strip()
        if not s and not t:
            break
        n, m = len(s), len(t)
        if n != m:
            print '[\n]'
            continue
        print '['
        cur = ''
        ans = ['' for i in xrange(n*2)]
        stack = []
        dfs(s, t, cur, stack, ans, 0)
        print ']'

if __name__ == '__main__':
    main()
