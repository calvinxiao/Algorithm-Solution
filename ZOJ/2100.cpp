/*
#Problem ID: 2100
#Submit Time: 2013-03-25 02:21:57
#Run Time: 80
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

using namespace std;

const int MAX = 10;
int n, m, g[MAX][MAX], v[MAX][MAX], ans, cnt;
char c;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int dfs(int x, int y) {
    if (!v[x][y]) {
        v[x][y] = 1;
        ans++;
        if (ans == cnt)
            return 1;
    }
    REP(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!v[nx][ny] && g[nx][ny]) {
            if (dfs(nx, ny))
                return 1;
        }
    }
    v[x][y] = 0;
    ans--;
    return 0;
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf("%d%d", &n, &m) && n && m) {
            //cout << n <<' ' <<m <<endl;
        memset(g, 0, sizeof g);
        memset(v, 0, sizeof v);
        ans = cnt = 0;
        REPN(i, 1, n) REPN(j, 1, m) {
            scanf(" %c", &c);
            if (c == '.') { g[i][j] = 1; cnt++;}
            else g[i][j] = 0;
        }
        dfs(1, 1);
        if (ans == cnt)
            printf("YES\n");
        else
            printf("NO\n");

	}
    return 0;
}
