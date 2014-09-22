/*
#Problem ID: 1921
#Submit Time: 2012-09-29 01:12:20
#Run Time: 690
#Run Memory: 208
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int dx[2] = {0, 1};
int dy[2] = {1, 0};

char g[2][102][102];
int tc, TC, DAYS, n, m, i, j, k, day;

int main()
{
	scanf("%d", &TC);
	//cin >> TC;
	for(; tc < TC; ++tc) {
		if(tc) cout << endl;

		scanf("%d%d%d", &n, &m, &DAYS);
		//cin >> n >> m >> DAYS;

		memset(g, 0, sizeof g);

		for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j) {
			scanf(" %c", &g[0][i][j]);
			//cin >> g[0][i][j];
			g[1][i][j] = g[0][i][j];
		}

		day = 0;
		while(day < DAYS) {
			for(i = 1; i <= n; ++i)
			for(j = 1; j <= m; ++j) {
				g[!(day&1)][i][j] = g[day&1][i][j];
			}

			for(i = 1; i <= n; ++i)
			for(j = 1; j <= m; ++j) {
				for(k = 0; k < 2; ++k) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if(g[0][ni][nj] != 0) {
						char THIS = g[day%2][i][j];
						char that = g[day%2][ni][nj];

						if(THIS == 'R' && that == 'S') {
							g[(day+1)%2][ni][nj] = 'R';
						}
						else if(THIS == 'S' && that == 'R') {
							g[(day+1)%2][i][j] = 'R';
						}
						else if(THIS == 'S' && that == 'P') {
							g[(day+1)%2][ni][nj] = 'S';
						}
						else if(THIS == 'P' && that == 'S') {
							g[(day+1)%2][i][j] = 'S';
						}
						else if(THIS == 'P' && that == 'R') {
							g[(day+1)%2][ni][nj] = 'P';
						}
						else if(THIS == 'R' && that == 'P') {
							g[(day+1)%2][i][j] = 'P';
						}



					}
				}
			}

			day += 1;
		}

		for(i = 1; i <= n; ++i) {
			for(j = 1; j <= m; ++j)
				cout << g[day&1][i][j];
			cout << endl;
		}
	}
	return 0;
}