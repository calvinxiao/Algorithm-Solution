/*
#Problem ID: 3160
#Submit Time: 2013-04-26 16:24:59
#Run Time: 120
#Run Memory: 900
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
using namespace std;

int n, m, aa, bb, dp[303][303], g[303][303], a[303];

int max(int x, int y) {
    if (x < y)
        return y;
    return x;
}

int main() {
    //freopen("0.in", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        memset(g, 0, sizeof g);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &aa, &bb);
            g[aa][bb] = g[bb][aa] = 1;
        }
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < n - 1; ++i)
            if (g[a[i]][a[i+1]])
                dp[i][i+1] = 2;
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                if (len % 2 == 0) {
                    if (dp[i+1][i+len-2] == i + len - 1 - i + 1 - 2 && g[a[i]][a[i+len-1]]) {
                        dp[i][i+len-1] = i + len - 1 - i + 1;
                        continue;
                    }
                }
                for (int j = i + 1; j < i + len - 1; ++j) {
                    dp[i][i+len-1] = max(dp[i][i+len-1], dp[i][j] + dp[j+1][i+len-1]);
                    dp[i][i+len-1] = max(dp[i][i+len-1], dp[i][j-1] + dp[j][i+len-1]);
                }
            }
        }
        printf("%d\n", dp[0][n-1]);
    }
    return 0;
}
