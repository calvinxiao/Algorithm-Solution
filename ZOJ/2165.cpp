/*
#Problem ID: 2165
#Submit Time: 2012-12-02 23:12:32
#Run Time: 10
#Run Memory: 188
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

const int MAX = 100;

char g[22][22];
bool v[22][22];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int sx, sy, n, m, cnt;

void dfs(int x, int y) {
	if(v[x][y]) return;
	else {
		//cout << x << ' ' << y << endl;
		v[x][y] = 1;
		cnt ++;
	}

	REP(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx && nx < n && 0 <= ny && ny < m && g[nx][ny] == '.')
			dfs(nx, ny);
	}
}

int main()
{
	//freopen("0.in", "r", stdin);

	while(1) {
		cin >> m >> n;
		if(n == 0 && m == 0) break;
		REP(i, n) REP(j, m) {
			cin >> g[i][j];
			if(g[i][j] == '@') {
				sx = i;
				sy = j;
			}
		}
		memset(v, 0, sizeof v);

		cnt = 0;
		dfs(sx, sy);

		cout << cnt << endl;
	}
    return 0;
}
