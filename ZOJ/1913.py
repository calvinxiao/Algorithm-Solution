#Problem ID: 1913
#Submit Time: 2013-05-30 21:40:45
#Run Time: 10
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

while 1:
    a, b = getints()
    if a == 0 and b == 0:
        break;
    if a > b:
        a, b = b, a
    ans = []
    stan = 0
    if a == 0:
        stan = 0
    else:
        while a != 0:
            c = b / a
            if c == 1:
                stan ^= 1
            else:
                stan ^= 1
                break
            a, b = b % a, a
    if stan & 1:
        print 'Stan wins'
    else:
        print 'Ollie wins'
    
