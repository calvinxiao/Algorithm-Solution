#Problem ID: 2420
#Submit Time: 2014-05-16 10:38:14
#Run Time: 360
#Run Memory: 2208
#ZOJ User: calvinxiao


import sys, datetime

def getline():
    return sys.stdin.readline()

def getint():
    return input()

def getints():
	return map(int, raw_input().split())

def getlist():
    return raw_input().split()

#sys.stdin = open("0.in", "r")

wd = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

while 1:
	days = input()
	if days == -1:
		break
	date = datetime.date(2000,1,1)
	td = datetime.timedelta(days=days)
	date2 = date + td
	print '%04d-%02d-%02d' % (date2.year, date2.month, date2.day),
	print wd[date2.weekday()]