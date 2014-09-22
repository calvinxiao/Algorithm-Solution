#Problem ID: 1243
#Submit Time: 2014-06-26 17:46:41
#Run Time: 0
#Run Memory: 140
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
    l = getline()
    if not l:
        break
    TC = int(l)
    for tc in xrange(1, TC + 1):
        l = raw_input()
        l = l.split("://", 1)
        protocol = l[0]
        l = l[1]
        host =  ""
        port = ""
        path = ""
        
        if (":" in l and "/" not in l) or (":" in l and "/" in l and l.index(":") < l.index("/")):
            l = l.split(":", 1)
            host = l[0]
            l = l[1]
            if "/" in l:
                l = l.split("/", 1)
                port = l[0]
                path = l[1]
            else:
                port = l
        elif "/" in l:
            l = l.split("/", 1)
            host = l[0]
            path = l[1]
        else:
            host = l
            
        if port == "":
            port = "<default>"
        if path == "":
            path = "<default>"
        print "URL #%d" % tc
        print "Protocol = %s" % protocol
        print "Host     = %s" % host
        print "Port     = %s" % port
        print "Path     = %s" % path
        print ""
    getline()
