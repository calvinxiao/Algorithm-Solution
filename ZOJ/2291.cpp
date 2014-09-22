/*
#Problem ID: 2291
#Submit Time: 2012-10-22 14:46:37
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

const int MAX = 100;

int n, m, sx, sy;
char g[22][22];
bool vis[22][22], gvis[22][22];
int doors[300], keys[300];
int cnt[300];
int main()
{
	//freopen("0.in", "r", stdin);

	char door[] = "ABCDE";
	char key[] = "abcde";

	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	//scanf(" %d %d", &n, &m);
	while(scanf(" %d %d", &n, &m) && n != 0 && m != 0) {
		memset(cnt, 0, sizeof cnt);
		memset(doors, 0, sizeof doors);
		memset(keys, 0, sizeof keys);
		memset(gvis, 0, sizeof gvis);

		bool found = false;

		REP(i, n) REP(j, m) {
			char t;
			scanf(" %c", &t);
			g[i][j] = t;
			if(t == 'S')
				sx = i, sy = j;
			cnt[t] += 1;
			doors[t] += 1;
		}

		queue<int> qx, qy;
		
		REP(time, 16) {
			memset(vis, 0, sizeof vis);
			qx.push(sx); qy.push(sy);
			while(!found && qx.size()) {
				int tx = qx.front(); qx.pop();
				int ty = qy.front(); qy.pop();
				//cout << g[tx][ty] << endl;
				//vis[tx][ty] = true;
				if(!gvis[tx][ty]) {
					gvis[tx][ty] = true;
					keys[g[tx][ty]] += 1;
				}

				//cout << time << ' ' << tx <<  ' ' << ty << endl;
				REP(i, 4) {
					int nx = tx + dx[i];
					int ny = ty + dy[i];
					if(0 <= nx && nx < n && 0 <= ny && ny < m && g[nx][ny] != 'X' && !vis[nx][ny]) {
						// do the keys
						REP(j, 5) {
							if(g[nx][ny] == door[j]) {
								//cout << key[j] << ' ' << cnt[key[j]] << ' ' << keys[key[j]] << endl;
								if(cnt[key[j]] == keys[key[j]])
									qx.push(nx), qy.push(ny), vis[nx][ny] = true;
							}

							if(g[nx][ny] == key[j])
								qx.push(nx), qy.push(ny), vis[nx][ny] = true;
						}

						if(g[nx][ny] == '.') qx.push(nx), qy.push(ny), vis[nx][ny] = true;

						if(g[nx][ny] == 'G') found = true;

					}
				}
			}
		}

		//cout << cnt['a'] << ' ' << keys['a'] << endl;

		if(found) cout << "YES\n";
		else 	  cout << "NO\n";

		//scanf("%d%d", &n, &m);
	}

	//cout << n << m << endl;
    return 0;
}
