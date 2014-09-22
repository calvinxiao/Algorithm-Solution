/*
#Problem ID: 2797
#Submit Time: 2013-04-27 01:28:09
#Run Time: 160
#Run Memory: 276
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b, p;
double g[111][111];

int main() {
    //freopen("0.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (!n)
            break;
        scanf("%d", &m);
        memset(g, 0, sizeof g);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &p);
            g[a][b] = g[b][a] = (double)p/100;
        }
        for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] < g[i][k] * g[k][j])
                g[i][j] = g[i][k] * g[k][j];
        }
        printf("%.6f percent\n", g[1][n] * 100);
    }

    return 0;
}
