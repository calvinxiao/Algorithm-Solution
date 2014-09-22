#Problem ID: 1244
#Submit Time: 2014-06-27 09:49:57
#Run Time: 10
#Run Memory: 140
#ZOJ User: calvinxiao

tc = 0
while 1:
    tc += 1
    n = input()
    if not n:
        break
    print "Program #%d" % tc
    f = {}
    f['a'] = 'a'
    for i in xrange(n):
        x, y = raw_input().split(" = ")
        if x not in f:
            f[x] = x
        if y not in f:
            f[y] = y
        t = f[x]
        while t != f[t]:
            t = f[t]
        f[x] = t
        t = f[y]
        while t != f[t]:
            t = f[t]
        f[y] = t
        f[f[x]] = f[y]
    l = f.keys()
    l.sort()
    
    ans = [c for c in l if f[c] == 'a']
    if len(ans):
        print ' '.join(ans),
        print ''
    else:
        print 'none'
    print ''
            
