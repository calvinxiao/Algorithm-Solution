/*
#Problem ID: 1372
#Submit Time: 2013-05-29 01:02:28
#Run Time: 10
#Run Memory: 192
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

int g[55][55], f[55], n, m;

int ff(int _) {
	if (f[f[_]] != f[_])
		f[_] = ff(f[_]);
	return f[_];
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (scanf("%d", &n) && n) {
		REP(i, n+1) REP(j, n+1)
			g[i][j] = 999;
		REPN(i, 1, n) f[i] = i;
		scanf("%d", &m);
		//memset(g, 0, sizeof g);
		REP(i, m) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (c < g[a][b])
				g[a][b] = g[b][a] = c;
		}
		int ans = 0, cnt = 0;
		while (cnt < n-1) {
			int a = 1, b = 1, c = 999;
			REPN(i, 1, n) REPN(j, i+1, n) {
				if (0 < g[i][j] && g[i][j] < c) {
					int fi = ff(i);
					int fj = ff(j);
					if (fi == fj)
						g[i][j] = g[j][i] = 0;
					else {
						a = i, b = j, c = g[i][j];
					}
				}
			}
			// found a, b, c;
			f[f[a]] = f[b];
			ans += c;
			g[a][b] = g[b][a] = 0;
			cnt++;
		}
		printf("%d\n", ans);
	}
    return 0;
}
