/*
#Problem ID: 3460
#Submit Time: 2013-03-24 00:49:17
#Run Time: 320
#Run Memory: 1752
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

const int BIG = (int)1e9 + 7;
const int MAX = 51;
const double eps = 1e-9;

int n, m, t1, t2, sp, xa[MAX], ya[MAX], xb[MAX], yb[MAX], g[MAX*MAX][MAX], pn[MAX*MAX], pm[MAX], vis[MAX];
double t[MAX*MAX][MAX], l, r, mid, ans;

double dis(int a, int b, int c, int d) {
    return sqrt((a-c)*(a-c) +(b-d)*(b-d));
}

void init() {
    REP(i, m) scanf("%d%d", &xb[i], &yb[i]);
    REP(i, n) scanf("%d%d", &xa[i], &ya[i]);
    REP(i, n) REP(j, m) REP(k, m) {
        t[i*m + j][k] = dis(xa[i], ya[i], xb[k], yb[k]) / sp + (j+1) * t1 / 60.0 + j * t2;
    }
}

int dfs(int u) {
    REP(v, m) if (g[u][v] && !vis[v]) {
        vis[v] = 1;
        if (pm[v] == -1 || dfs(pm[v])) {
            pm[v] = u;
            return 1;
        }

    }
    return 0;
}

int func(double T) {
    memset(g, 0, sizeof g);
    REP(i, n) REP(j, m) REP(k, m) {
        int a = i * m + j;
        if (T - t[a][k] > eps)
            g[a][k] = 1;
    }

    int cnt = 0;
    REP(i, n*m) pn[i] = -1;
    REP(i, m) pm[i] = -1;

    REP(u, n*m) if (pn[u] == -1) {
        memset(vis, 0, sizeof vis);
        if (dfs(u)) {
            cnt++;
            if (cnt == m)
                break;
        }
    }
    return (cnt == m);
}

int main() {
    //freopen("0.in", "r", stdin);
    while (~scanf("%d%d%d%d%d", &n, &m, &t1, &t2, &sp)) {
        init();
        l = 0.0; r = 1e9;
        while (r - l > eps) {
            mid = (l + r) / 2;
            if (func(mid)) {
                ans = mid; r = mid;
            }
            else
                l = mid;
        }
        printf("%.6f\n", ans);
    }
    return 0;
}
