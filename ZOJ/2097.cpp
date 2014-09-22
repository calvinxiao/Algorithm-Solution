/*
#Problem ID: 2097
#Submit Time: 2013-06-19 09:46:00
#Run Time: 0
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
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)
#define BIG 1000000009;
using namespace std;

int g[8][8], d[8][8][5], inq[8][8][5], sx, sy, tx, ty;

int main()
{
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
	//freopen("0.in", "r", stdin);
	while (1) {
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        if (sx || sy || tx || ty) {
            REP(i, 8) REP(j, 8) scanf("%d", &g[i][j]);
            REP(i, 8) REP(j, 8) REP(k, 5) d[i][j][k] = BIG;
            sx--; sy--; tx--; ty--;
            queue<int> qx, qy, qs;
            memset(inq, 0, sizeof inq);
            qx.push(sx); qy.push(sy); qs.push(1);
            inq[sx][sy][1] = 1;
            d[sx][sy][1] = 0;

            while (!qx.empty()) {
                int x = qx.front(); qx.pop();
                int y = qy.front(); qy.pop();
                int s = qs.front(); qs.pop();
                inq[x][y][s] = 0;
                REP(i, 4) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx > 7 || ny < 0 || ny > 7)
                        continue;
                    int cost = s * g[nx][ny];
                    int ns = (cost & 3) + 1;
                    if (d[nx][ny][ns] > d[x][y][s] + cost) {
                        d[nx][ny][ns] = d[x][y][s] + cost;
                        if (!inq[nx][ny][ns]) {
                            qx.push(nx); qy.push(ny); qs.push(ns);
                            inq[nx][ny][ns] = 1;
                        }
                    }
                }
            }

            int ans = BIG;
            REP(i, 5) {
                ans = min(ans, d[tx][ty][i]);
            }
            printf("%d\n", ans);
        } else
            break;
	}
    return 0;
}
