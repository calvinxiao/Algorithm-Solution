#Problem ID: 3785
#Submit Time: 2014-05-14 16:46:15
#Run Time: 1870
#Run Memory: 292
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

tc = input()
days = ["Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]
gao = [0,1,5,4,1,4,5,5,6,0,4,6,0,6,6,0,2,0,1,6,0,0,1,5,6,3,0,6,6,0,1,4,6,5,6,6,0,2,4,5,0,6,6,0,4,3,0,3,4,4,5,6,3,5,6,5,5,6,1,6,0,5,6,6,0,4,5,2,6,5,5,6,0,3,5,4,5,5,6,1,3,4,6,5,5,6,3,2,6,2,3,3,4,5,2,4,5,4,4,5,0,5,6,4,5,5,6,3,4,1,5,4,4,5,6,2,4,3,4,4,5,0,2,3,5,4,4,5,2,1,5,1,2,2,3,4,1,3,4,3,3,4,6,4,5,3,4,4,5,2,3,0,4,3,3,4,5,1,3,2,3,3,4,6,1,2,4,3,3,4,1,0,4,0,1,1,2,3,0,2,3,2,2,3,5,3,4,2,3,3,4,1,2,6,3,2,2,3,4,0,2,1,2,2,3,5,0,1,3,2,2,3,0,6,3,6,0,0,1,2,6,1,2,1,1,2,4,2,3,1,2,2,3,0,1,5,2,1,1,2,3,6,1,0,1,1,2,4,6,0,2,1,1,2,6,5,2,5,6,6,0,1,5,0,1,0,0,1,3,1,2,0,1,1,2,6,0,4,1,0,0,1,2,5,0,6,0,0,1,3,5,6,1,0,0]

while tc:
	tc -= 1
	n = input()
	print days[gao[n % 294]]
