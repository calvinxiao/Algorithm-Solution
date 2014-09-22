/*
#Problem ID: 2922
#Submit Time: 2012-11-26 11:59:19
#Run Time: 220
#Run Memory: 4100
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

int g[1001][1001];
bool col[1001];
int main()
{
	//freopen("0.in", "r", stdin);
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		REP(i, n) REP(j, m)
			scanf("%d", &g[i][j]);
		memset(col, 0, sizeof col);

		int ans = 0;
		for(int i = n - 1; i >= 0; --i) {
			/*
			for(int j = m - 1; j >= 0; --j) {
				if(g[i][j] != 0) {
					if(!col[j] && g[i][j] > 0)
						ans += 1;
					if(g[i][j] < 0)
						g[i][j] = -g[i][j];

					col[j] = true;

					for(int k = 1; k <= g[i][j] && j - k >= 0; ++k) {
						if(g[i][j-k] > 0)
							g[i][j-k] = -g[i][j-k];
					}
				}
			}
			*/
			int end = m;
			int j = m - 1;
			while(j >= 0) {
				int t = g[i][j];
				if(t != 0) {
					if(!col[j] && j < end) {
						ans += 1;
					}
					
					col[j] = true;

					if (end > j - t)
						end = j - t;
					if(end < 0)
						end = 0;
				}
				--j;
			}
		}

		printf("%d\n", ans);
	}
    return 0;
}
