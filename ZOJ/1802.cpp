/*
#Problem ID: 1802
#Submit Time: 2013-08-06 22:34:02
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

using namespace std;

#define N 15
int g[N][N], n, ans, color[N];
double x[N], y[N];

int dfs(int v, int c) {
    //printf("%d %d\n", v, c);
    color[v] = c;
    REP(i, n) if (g[v][i] && color[i] == c) {
        color[v] = 0;
        return 0;
    }
    REP(i, n) if (g[v][i] && !color[i]) {
        int good = 0;
        for (int cc = 1; cc <= ans; cc++) if (cc != c) {
            if (dfs(i, cc)) {
                good = 1;
                break;
            }
        }
        if (!good) {
            color[v] = 0;
            return 0;
        }

    }
    return 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    int tc = 0;
    while (~scanf("%d", &n) && n != 0) {
        tc++;
        REP(i, n) scanf("%lf%lf", x+i, y+i);
        memset(g, 0, sizeof g);
        REP(i, n) REP(j, n) if (i < j){
            double d = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
            if (d < 400.00000001)
                g[i][j] = g[j][i] = 1;
        }

        for (ans = 1; ans <= n; ans++) {
            int good = 1;
            memset(color, 0, sizeof color);
            REP(i, n) if (!color[i]) {
                dfs(i, 1);
            }
            REP(i, n) if (!color[i]) good = 0;
            if (good)
                break;
        }
        printf("The towers in case %d can be covered in %d frequencies.\n", tc, ans);
    }
    return 0;
}
