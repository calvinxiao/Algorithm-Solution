#Problem ID: 1099
#Submit Time: 2014-05-14 15:16:05
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

ls = []
for line in sys.stdin:
	line = line.replace('\n', ' ').replace('\t', ' ')
	for s in line.split():
		ls.append(s)
ans = [[]]
i = 0
first = 0
cnt = 0
for s in ls:
	if s == '<br>':
		ans.append([])
		i += 1
		cnt = 0
		first = 0
	elif s == '<hr>':
		if len(ans[i]) > 0:
			ans.append([])
			i += 1
		ans[i].append('-' * 80)
		ans.append([])
		i += 1
		cnt = 0
		first = 0
	else:
		n = len(s)
		if cnt + n + first <= 80:
			ans[i].append(s)
			cnt += n + first
			first = 1
		else:
			i += 1
			ans.append([])
			ans[i].append(s)
			cnt = n
			first = 1
for line in ans:
	print ' '.join(line)