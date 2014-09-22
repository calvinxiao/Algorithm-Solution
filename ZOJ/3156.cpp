/*
#Problem ID: 3156
#Submit Time: 2013-04-26 13:18:49
#Run Time: 50
#Run Memory: 752
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

typedef long long LL;

using namespace std;

const int MAX = 102;

int n, m;
int X[MAX], Y[MAX], x[MAX], y[MAX], good[MAX][MAX], pm[MAX], vis[MAX];
LL t[MAX][MAX];
double v;
set<LL> S;
vector<LL> T;

void init()
{
    for (int i = 0; i < n; ++i)
        scanf("%d%d", X+i, Y+i);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", x+i, y+i);
    scanf("%lf", &v);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            LL temp = (LL)(X[i] - x[j]) * (X[i] - x[j]) + (LL)(Y[i] - y[j]) * (Y[i] - y[j]);
            t[i][j] = temp;
            S.insert(temp);
        }
    }
}

int dfs(int u, LL ti) {
    for (int j = 0; j < m; ++j) if (!vis[j] && t[u][j] <= ti) {
        vis[j] = 1;
        if (pm[j] == -1 || dfs(pm[j], ti)) {
            pm[j] = u;
            return 1;
        }
    }
    return 0;
}

int BM(LL ti) {
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (t[i][j] <= ti)
                good[i][j] = 1;
            else
                good[i][j] = 0;
        }
    }
    */
    int cnt = 0;
    memset(pm, -1, sizeof pm);
    for (int i = 0; i < n; ++i) {
        memset(vis, 0, sizeof vis);
        if (!dfs(i, ti))
            break;
        else
            cnt++;
    }
    return cnt;
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf("%d%d", &n, &m)) {
        S.clear(); T.clear();
        init();
        if (n == 0) {
            printf("0.00\n");
            continue;
        }
        for (set<LL>::iterator it = S.begin(); it != S.end(); it++)
            T.push_back(*it);
        int l = 0, r = T.size() - 1, m, ans = 0;
        while (l <= r) {
            m = (l+r) >> 1;
            int cnt = BM(T[m]);
            if (cnt == n) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        printf("%.2f\n", sqrt(1.0 * T[ans]) / v);
	}
    return 0;
}
