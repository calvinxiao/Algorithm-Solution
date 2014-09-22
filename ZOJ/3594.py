#Problem ID: 3594
#Submit Time: 2013-03-09 15:08:06
#Run Time: 50
#Run Memory: 320
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
a = ["Jia", "Yi", "Bing", "Ding", "Wu", "Ji", "Geng", "Xin", "Ren", "Gui"]
b = ["Zi", "Chou", "Yin", "Mao", "Chen", "Si", "Wu", "Wei", "Shen", "You", "Xu", "Hai"]
sixty = []

cnt, i, j = 0, 0, 0
while cnt < 60:
    sixty.append(a[i] + b[j].lower())
    #print b[i].lower()
    i = (i+1) % 10
    j = (j+1) % 12
    cnt += 1

T = input()
while T:
    T -= 1
    year = input()
    if year >= 0:
        year += 60
        year -= 3
        year %= 60
    else:
        year = -year
        year += 2
        year = 60 - year % 60
    print sixty[year-1]
