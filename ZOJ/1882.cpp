/*
#Problem ID: 1882
#Submit Time: 2013-03-04 16:25:22
#Run Time: 30
#Run Memory: 228
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 105;
int e[MAX][MAX], n, m, cn[MAX], cm[MAX], vis[MAX];
double S, V, xa[MAX], ya[MAX], xb[MAX], yb[MAX];

double ok(int i, int j)
{
    double dis = sqrt((xa[i] - xb[j]) * (xa[i] - xb[j]) + (ya[i] - yb[j]) * (ya[i] - yb[j]));
    double time = dis / V;
    return (S - time > 1e-9);
}

int dfs(int u)
{
    for (int v = 0; v < m; ++v) {
        if (e[u][v] && ! vis[v]) {
            vis[v] = 1;
            if (cm[v] == -1 || dfs(cm[v])) {
                cn[u] = v;
                cm[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf("%d%d%lf%lf", &n, &m, &S, &V)) {
        REP(i, n) scanf("%lf%lf", &xa[i], &ya[i]);
        REP(i, m) scanf("%lf%lf", &xb[i], &yb[i]);
        memset(e, 0, sizeof e);
        memset(cn, -1, sizeof cn);
        memset(cm, -1, sizeof cm);
        int ans = 0;
        REP(i, n) REP(j, m) e[i][j] = ok(i, j);
        for (int i = 0; i< n; ++i) {
            if (cn[i] == -1) {
                memset(vis, 0, sizeof vis);
                ans += dfs(i);
            }
        }
        printf("%d\n", n - ans);
	}
    return 0;
}
