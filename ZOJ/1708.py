#Problem ID: 1708
#Submit Time: 2012-05-01 00:27:25
#Run Time: 10
#Run Memory: 320
#ZOJ User: calvinxiao

import sys

def main():
	while(True):
		rcs = sys.stdin.readline()
		r = int(rcs.split(" ")[0])
		c = int(rcs.split(" ")[1])
		s = int(rcs.split(" ")[2])
		
		if(r == 0 and c == 0 and s == 0):
			break
			
		g= [[' ' for i in range(c)] for j in range(r)]
	
		for i in range(r):
			g[i] = sys.stdin.readline()
		
		pos = s - 1
		route = []
		route.append(pos)
		
		while(True):
			x = pos / c
			y = pos % c
			
			if(g[x][y] == 'N'):
				x -= 1
			elif(g[x][y]  == 'S'):
				x += 1
			elif(g[x][y]  == 'W'):
				y -= 1
			elif(g[x][y]  == 'E'):
				y += 1
			
			if(x<0 or x>=r or y<0 or y>=c):
				print "%d step(s) to exit" % len(route)
				break
				
			pos = x * c + y
	
			if(route.count(pos) > 0):
				print "%d step(s) before a loop of %d step(s)" % (route.index(pos), len(route) - route.index(pos) )
				break
				
			route.append(pos)
	
	return 0

if __name__ == '__main__':
	try:
		main()
	except:
		0
	

		
	
	


