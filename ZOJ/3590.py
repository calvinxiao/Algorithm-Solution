#Problem ID: 3590
#Submit Time: 2012-09-19 18:06:44
#Run Time: 230
#Run Memory: 1840
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
    n = int(line)
    a = [int(num) for num in getlist()]
    cnt = [0 for i in xrange(4)]
    ans = 0
    rest = 0
    for num in a:
        if num < 3:
            cnt[num] += 1
        else:
            if num == 4:
                ans += 1
                cnt[1] += 1
                rest += 1
            elif (num+1) % 3 == 0:
                ans += (num+1)/3
                rest += (num+1)/3 - 1
            elif (num+2) % 3 == 0:
                ans += (num+2)/3
                rest += (num+2)/3 - 2
            else:
                ans += num / 3
                rest += num / 3
    #print ans, cnt[1], cnt[2], rest
    #put the rest to two, no gain no loss
    ans += min(rest, cnt[2])
    #print ans, cnt[1], cnt[2], rest
    if rest != 0:
        if cnt[1] != 0:
            t = rest / 2
            tt = min(cnt[1], t)

            while cnt[1] != 0 and t != 0:
                cnt[1] -= tt
                rest -= tt
                ans += tt
                t = rest / 2
                tt = min(cnt[1], t)
    #print ans, cnt[1], cnt[2], rest
    if rest != 0:
        if rest >= 3:
            ans += (rest-3)/2 + 1
            rest = rest - (rest-3)/2*2 - 3
    #print ans, cnt[1], cnt[2], rest
    print ans
            
        
    
