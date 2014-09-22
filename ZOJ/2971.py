#Problem ID: 2971
#Submit Time: 2014-05-20 11:55:40
#Run Time: 60
#Run Memory: 288
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

def solve(s):
    d = {}
    d['zero'] = 0
    d['one'] = 1
    d['two'] = 2
    d['three'] = 3
    d['four'] = 4
    d['five'] = 5
    d['six'] = 6
    d['seven'] = 7
    d['eight'] = 8
    d['nine'] = 9
    d['ten'] = 10
    d['eleven'] = 11
    d['twelve'] = 12
    d['thirteen'] = 13
    d['fourteen'] = 14
    d['fifteen'] = 15
    d['sixteen'] = 16
    d['seventeen'] = 17
    d['eighteen'] = 18
    d['nineteen'] = 19
    d['twenty'] = 20
    d['thirty'] = 30 
    d['forty'] = 40
    d['fifty'] = 50
    d['sixty'] = 60
    d['seventy'] = 70
    d['eighty'] = 80
    d['ninety'] = 90
    
    s = s.strip()
    ret = 0
    if 'millions' in s:
        s = s.split('millions')
        return solve(s[0]) * 1000000 + solve(s[1])
    elif 'million' in s:
        s = s.split('million')
        return solve(s[0]) * 1000000 + solve(s[1])
    elif 'thousands' in s:
        s = s.split('thousands')
        return solve(s[0]) * 1000 + solve(s[1])
    elif 'thousand' in s:
        s = s.split('thousand')
        return solve(s[0]) * 1000 + solve(s[1])
    elif 'hundreds' in s:
        s = s.split('hundreds')
        return solve(s[0]) * 100 + solve(s[1])
    elif 'hundred' in s:
        s = s.split('hundred')
        return solve(s[0]) * 100 + solve(s[1])
    s = s.replace('and', '').strip()
    s = s.split(' ')
    for c in s:
        c = c.replace(' ', '')
        if c != '':
            ret += d[c]
    return ret
    

while tc:
    tc -= 1
    line = getline()
    print solve(line.strip())
