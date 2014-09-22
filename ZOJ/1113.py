#Problem ID: 1113
#Submit Time: 2012-08-16 01:14:38
#Run Time: 10
#Run Memory: 316
#ZOJ User: calvinxiao

import sys
a = 1
b = 2
print 'n e'
print '- -----------'
for i in xrange(10):
    if i == 0:
	print 0, 1
    elif i == 1:
	print 1, 2
    else:
	a *= 1.0/i
	b += a
	if i == 2:
	    print '2 2.5'
	else:
	    print '%d %.9f' % (i, b)
	
	