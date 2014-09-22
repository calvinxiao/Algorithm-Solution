#Problem ID: 1006
#Submit Time: 2014-04-22 12:52:20
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

def main():
    while 1:
        l = raw_input()
        if l == '0':
            break
        k, s = l.split()
        n = len(s)
        ans = ['' for i in xrange(n)]
        ls = '_abcdefghijklmnopqrstuvwxyz.'
        m = len(ls)
        for i in xrange(n):
            j = int(k) * i % n
            for ii in xrange(m):
                t = ls[(ii - i + 28) % 28]
                if t == s[i]:
                    ans[j] = ls[ii]
                    break
        print ''.join(ans)

if __name__ == '__main__':
    main()
