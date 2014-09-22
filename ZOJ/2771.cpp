/*
#Problem ID: 2771
#Submit Time: 2013-04-27 12:00:26
#Run Time: 0
#Run Memory: 180
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long dp[4][66];

int main() {
    //freopen("0.in", "r", stdin);
    dp[0][0] = 1;
    for (int i = 1; i < 61; ++i) {
        if (i & 1) {
            for (int j = 1; j < 4; ++j)
                for (int k = 0; k < j; ++k)
                    dp[j][i] += dp[k][i-1];

        } else {
            for (int j = 0; j < 3; ++j)
                for (int k = j + 1; k < 4; ++k)
                    dp[j][i] += dp[k][i-1];
        }
    }
    while (~scanf("%d", &n)) {
        if (n == 0)
            puts("1");
        else {
            long long ans = 0;
            for (int i = 0; i < 4; ++i)
                ans += dp[i][n];
            printf("%lld\n", ans);
        }
    }
    return 0;
}
