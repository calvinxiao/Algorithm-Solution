/*
#Problem ID: 1364
#Submit Time: 2013-03-09 22:00:26
#Run Time: 0
#Run Memory: 228
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

const int MAX = 101;
int n, m, k, t, a, b, ans, pn[MAX], pm[MAX], v[MAX], g[MAX][MAX];

int go(int u) {
	REP(i, m) if (g[u][i] && ! v[i]) {
		v[i] = 1;
		if (pm[i] == -1 || go(pm[i])) {
			pn[u] = i;
			pm[i] = u;
			return 1;
		}
	}
	return 0;
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (scanf("%d", &n) && n) {
		scanf("%d%d", &m, &k);
		memset(g, 0, sizeof g);
		REP(i, k) {
			scanf("%d%d%d", &t, &a, &b);
			a--, b--;
			g[a][b] = 1;
		}
		ans = 0;
		REP(i, n) pn[i] = -1;
		REP(i, m) pm[i] = -1;
		REP(i, n) if (pn[i] == -1) {
			memset(v, 0, sizeof v);
			ans += go(i);
		}
		printf("%d\n", ans);
	}
    return 0;
}
