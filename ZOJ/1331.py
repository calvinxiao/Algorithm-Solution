#Problem ID: 1331
#Submit Time: 2013-02-27 11:40:11
#Run Time: 1160
#Run Memory: 316
#ZOJ User: calvinxiao

cube = [a*a*a for a in xrange(201)]
mp = {}
for i in xrange(201):
    mp[cube[i]] = i

ans = []
for b in xrange(2, 201):
    for c in xrange(b+1, 201):
        for d in xrange(c+1, 201):
            t = cube[b] + cube[c] + cube[d]
            if t in mp:
                #print t, int(t**0.3333+0.5)
                ans.append([mp[t], b, c, d])
ans.sort()
for i in xrange(len(ans)):
    print "Cube = %d, Triple = (%d,%d,%d)" % (ans[i][0],ans[i][1],ans[i][2],ans[i][3])
