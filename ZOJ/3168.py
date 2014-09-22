#Problem ID: 3168
#Submit Time: 2012-09-13 16:33:24
#Run Time: 200
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

while 1:
    line = getline()
    if not line:
        break
    line = list(line.strip())
    ans = '' + ('Z' * line.count('Z')) + ('O' * line.count('O'))+ ('J' * line.count('J'))+ ('7' * line.count('7'))
    IN = 'ZOJ7'
    for c in line:
        if not c in IN:
            ans += c
    print ans
