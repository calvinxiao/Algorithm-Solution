/*
#Problem ID: 1140
#Submit Time: 2013-03-15 17:58:04
#Run Time: 640
#Run Memory: 308
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
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 100;

int n, m, vis[301], g[101][301], pn[101], pm[301];

int dfs(int u) {
	for (int v = 1; v <= m; ++v) if (g[u][v] && !vis[v]) {
		vis[v] = 1;
		if (pm[v] == -1 || dfs(pm[v])) {
			pn[u] = v; pm[v] = u;
			return 1;
		}
	}
	return 0;
}

int BM() {
	int cnt = 0;
	memset(pn, -1, sizeof pn);
	memset(pm, -1, sizeof pm);
	for (int u = 1; u <= n; ++u) {
		memset(vis, 0, sizeof vis);
		if (pn[u] == -1)
			cnt += dfs(u);
		if (cnt < u) 
			break;
	}
	return cnt;
}

int main()
{
	//freopen("0.in", "r", stdin);
	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> m;
		memset(g, 0, sizeof g);
		REP(i, n) {
			int t; cin >> t;
			REP(j, t) {
				int k; cin >> k;
				g[i+1][k] = 1;
			}
		}
		int ans = BM();
		if (ans == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
    return 0;
}
