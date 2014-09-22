#Problem ID: 2191
#Submit Time: 2012-11-09 00:59:08
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getints():
	return [int(num) for num in getlist()]

def getlist():
    return sys.stdin.readline().strip().split()

#sys.stdin = open("0.in", "r")
while 1:
	line = getline()
	if not line:
		break
	IN = [int(num) for num in line.split()]
	C = IN[0]
	A = (C + IN[2] - 2 * IN[1]) / 2.0
	B = IN[1] - A - C
	print int(A * 9 + 3 * B + C), int(A * 16 + B * 4 + C), int(A * 25 + B * 5 + C)
    
