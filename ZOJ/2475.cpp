/*
#Problem ID: 2475
#Submit Time: 2012-10-12 18:05:02
#Run Time: 0
#Run Memory: 196
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

const int MAX = 101;
bool g[MAX][MAX], vis[MAX];
int n, a, b, e;

bool dfs(int v) {
	if(g[v][v]) return true;
	vis[v] = true;
	REP(i, MAX)
		if(g[v][i] && !vis[i] && dfs(i)) return true;
	return false;
}

int main()
{
	while(1) {
		scanf("%d", &n);
		if(n < 0) break;
		memset(g, 0, sizeof g);
		memset(vis, 0, sizeof vis);
		REP(i, n) {
			scanf("%d%d", &a, &b);
			if(a != b)
				g[a-1][b-1] = 1;
		}
		REP(k, MAX) REP(i, MAX) REP(j, MAX) 
			if(g[i][k] && g[k][j]) g[i][j] = 1;
		scanf("%d", &e);
		e--;
		if(dfs(e)) cout << "No\n";
		else cout << "Yes\n";
	}
    return 0;
}
