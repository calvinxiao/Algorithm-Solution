#Problem ID: 1084
#Submit Time: 2014-05-14 10:54:38
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

# return max number 
def dfs(u, edge, num):
	align = []
	for v in edge[u]:
		align.append(num[v])
	for i in xrange(1, 27):
		if i not in align:
			num[u] = i
			break
	ret = num[u]
	for v in edge[u]:
		if num[v] == 0:
			t = dfs(v, edge, num)
			if ret < t:
				ret = t
	return ret


while 1:
	n = input()
	if n == 0:
		break
	edge = {}
	for i in xrange(n):
		s = raw_input().split(':')
		edge[s[0]] = list(s[1])
	ans = 0
	num = {}
	for key in edge:
		num[key] = 0
	for key in edge:
		t = dfs(key, edge, num)
		if ans < t:
			ans = t
	wtf = 'channels'
	if ans == 1:
		wtf = 'channel'

	print '%d %s needed.' % (ans, wtf)

