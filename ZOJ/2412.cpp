/*
#Problem ID: 2412
#Submit Time: 2013-06-08 16:02:05
#Run Time: 0
#Run Memory: 212
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

const int MAX = 55;

int n, m;
int g[55][55];
int v[55][55];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, dir[30][4];
int o[4];

int dfs(int x, int y){
    if (v[x][y])
        return 1;
    v[x][y] = 1;
    REP(i, 4) if (dir[g[x][y]][i]) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && 0 <= ny && nx < n && ny < m && !v[nx][ny] && dir[g[nx][ny]][o[i]])
            dfs(nx, ny);
    }
    return 0;
}

int main()
{

    dir['A'-'A'][0] = 1;
    dir['A'-'A'][3] = 1;
    dir['B'-'A'][0] = 1;
    dir['B'-'A'][1] = 1;
    dir['C'-'A'][2] = 1;
    dir['C'-'A'][3] = 1;
    dir['D'-'A'][1] = 1;
    dir['D'-'A'][2] = 1;
    dir['E'-'A'][0] = 1;
    dir['E'-'A'][2] = 1;
    dir['F'-'A'][1] = 1;
    dir['F'-'A'][3] = 1;
    dir['G'-'A'][0] = 1;dir['G'-'A'][1] = 1;dir['G'-'A'][3] = 1;
    dir['H'-'A'][0] = 1;dir['H'-'A'][2] = 1;dir['H'-'A'][3] = 1;
    dir['I'-'A'][1] = 1;dir['I'-'A'][2] = 1;dir['I'-'A'][3] = 1;
    dir['J'-'A'][0] = 1;dir['J'-'A'][1] = 1;dir['J'-'A'][2] = 1;
    dir['K'-'A'][0] = 1;dir['K'-'A'][1] = 1;dir['K'-'A'][2] = 1;dir['K'-'A'][3] = 1;
    o[0] = 2; o[2] = 0; o[1] = 3; o[3] = 1;

	//freopen("0.in", "r", stdin);

	while (1) {
        cin >> n >> m;
        if (n == -1 && m == -1)
            break;
        memset(g, 0, sizeof g);
        memset(v, 0, sizeof v);
        REP(i, n) {
            REP(j, m) {
                char c; cin >> c;
                g[i][j] = c - 'A';
            }
        }
        int ans = 0;
        REP(i, n) {
            REP(j, m) {
                if (!dfs(i, j))
                    ans++;
            }
        }
        cout << ans << endl;
	}

    return 0;
}
