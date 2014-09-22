/*
#Problem ID: 2252
#Submit Time: 2012-11-09 00:11:52
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
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

const int MAX = 100;
#define BIG 1000000007

int n, m, sx, sy, tx, ty, nx, ny, nk, x, y;
int grid[20][20],  dp[20][20][4];
bool used[20][20][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int walk() {
	//spfa
	if(sx == tx && sy == ty) return 0;
	if(grid[tx][ty] == -1) return -1;
	int ans = BIG;

	REP(i, n) REP(j, m) REP(k, 4) {
		used[i][j][k] = 0;
		dp[i][j][k] = BIG;
	}

	dp[sx][sy][(0+grid[sx][sy])&3] = grid[sx][sy];
	queue<int> qx, qy, qk;
	qx.push(sx), qy.push(sy), qk.push((0+grid[sx][sy])&3);
	while(qx.size()) {
		x = qx.front();
		y = qy.front();
		int k = qk.front();
		qx.pop(); qy.pop(); qk.pop();
		used[x][y][k] = 0;
		//if i stays
		for(int kk = 1; kk <= 3; ++kk) {
			if(dp[x][y][k] + kk < dp[x][y][(k+kk)&3]) {
				dp[x][y][(k+kk)&3] = dp[x][y][k] + kk;
				if(!used[x][y][(k+kk)&3]) {
					qx.push(x); qy.push(y); qk.push((k+kk)&3);
					used[x][y][(k+kk)&3] = 1;
				}
			}
		}

		nx = x + dx[k];
		ny = y + dy[k];
		if(0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] != -1) {
			int temp = dp[x][y][k] + 1;
			if(nx == tx && ny == ty && temp < ans) 
				ans = temp;
			temp += grid[nx][ny];
			int nextk = (k+1+ grid[nx][ny])&3;
			if(temp < dp[nx][ny][nextk]) {
				dp[nx][ny][nextk] = temp;
				if(!used[nx][ny][nextk]) {
					qx.push(nx); qy.push(ny); qk.push(nextk);
					used[nx][ny][nextk] = 1;
				}
			}
		}
	}

	if(ans == BIG) ans = -1;
	return ans;
}

int main()
{
	//freopen("0.in", "r", stdin);
	
	while(cin >> m >> n >> sx >> sy >> tx >> ty) {
		REP(i, n) REP(j, m) cin >> grid[i][j];
		int ans = walk();
		cout << ans << endl;
	}

    return 0;
}
