/*
#Problem ID: 1438
#Submit Time: 2012-10-30 22:02:31
#Run Time: 0
#Run Memory: 192
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

const int MAX = 10, BIG = 5000;
char g[MAX][MAX][MAX];
int dp[MAX][MAX][MAX];
bool inq[MAX][MAX][MAX];

int N;

int main()
{
	int dx[] = {-1, 0, 0, 0, 0, 1};
	int dy[] = {0, -1, 0, 0, 1, 0};
	int dz[] = {0, 0, -1, 1, 0, 0};
	int sx, sy, sz, x, y, z, nx, ny, nz, tx, ty, tz;

	//freopen("0.in", "r", stdin);
	string s;
	while ( cin >> s >> N) {

		REP(k, N) REP(j, N) REP(i, N) {
			cin >> g[i][j][k];
			dp[i][j][k] = BIG;
			inq[i][j][k] = false;
		}

		cin >> sx >> sy >> sz >> x >> y >> z;

		cin >> s;

		dp[sx][sy][sz] = 0;
		bool updated = true;
		while (updated) {
			updated = false;

			REP(i, N) REP(j, N) REP(k, N) REP(idx, 6){
				nx = i + dx[idx];
				ny = j + dy[idx];
				nz = k + dz[idx];

				if (0 <= nx && nx < N && 0 <= ny && ny < N && 0 <= nz && nz < N && g[nx][ny][nz] == 'O') {
					if (dp[i][j][k] + 1 < dp[nx][ny][nz]) {
						updated = true;
						dp[nx][ny][nz] = dp[i][j][k] + 1;
					}
				}
			}
		}

		if (dp[x][y][z] != BIG) {
			cout << N << ' ' << dp[x][y][z] << endl;
		}
		else 
			cout << "NO ROUTE\n";

	}
    return 0;
}
