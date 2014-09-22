#Problem ID: 1884
#Submit Time: 2012-09-06 01:53:02
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def getline():
    return sys.stdin.readline()

def getint():
    return int(sys.stdin.readline())

def getlist():
    return sys.stdin.readline().strip().split()

s = []
s = "`1234567890-=#QWERTYUIOP[]\\#ASDFGHJKL;'#ZXCVBNM,./"
        
while 1:
    line = getline()
    if not line:
        break
    ss = line
    ans = []
    for c in ss:
        if c == '\n':
            continue
        if c == ' ':
            ans.append(' ')
            continue
        i  = s.find(c)
        ans.append(s[i-1])
    print ''.join(ans)
            
    

    
