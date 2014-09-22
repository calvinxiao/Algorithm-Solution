/*
#Problem ID: 3166
#Submit Time: 2013-02-18 17:39:06
#Run Time: 240
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

using namespace std;

const int MAX = 1000000007;

int n, c, m, a, b, d, t, h[101], g[101][101];


int main()
{
	//freopen("0.in", "r", stdin);
	while(~scanf("%d%d", &n, &c)) {
		REP(i, n) REP(j, n) g[i][j] = MAX;
		memset(h, 0, sizeof h);
		REP(i, c) {
			scanf("%d", &t);
			t--;
			h[t] = 1;
		}
		scanf("%d", &m);
		REP(i, m) {
			scanf("%d%d%d", &a, &b, &d);
			a--; b--;
			g[a][b] = d;
		}
		int ans = -1;
		int ma = MAX;
		REP(k, n) REP(i, n) REP(j, n) {
			if (g[i][k] != MAX && g[k][j] != MAX && g[i][j] > g[i][k] + g[k][j])
				g[i][j] = g[i][k] + g[k][j];
		}
		REP(j, n) if (h[j]) {
			if (g[j][j] < ma) {
				ma = g[j][j];
				ans = j;
			}
		}

		if (ans==-1) {
			printf("I will nerver go to that city!\n");
		} else
			printf("%d\n", ans+1);
	}
    return 0;
}
