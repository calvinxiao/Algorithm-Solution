#Problem ID: 1858
#Submit Time: 2012-09-06 01:33:17
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

d = {}
d['B'] = '1'
d['F'] = '1'
d['P'] = '1'
d['V'] = '1'

d['C'] = '2'
d['G'] = '2'
d['J'] = '2'
d['K'] = '2'
d['Q'] = '2'
d['S'] = '2'
d['X'] = '2'
d['Z'] = '2'

d['D'] = '3'
d['T'] = '3'

d['L'] = '4'

d['M'] = '5'
d['N'] = '5'

d['R'] = '6'
        
while 1:
    line = getline()
    if not line:
        break
    s = line.strip()
    ans = []
    if s[0] in d:
        ans.append(d[s[0]])
    for i in xrange(1, len(s)):
        if s[i] in d:
            if (not s[i-1] in d) or (s[i-1] in d and d[s[i]] != d[s[i-1]]):
                ans.append(d[s[i]])
    print ''.join(ans)
            
    

    
