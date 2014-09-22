/*
#Problem ID: 3725
#Submit Time: 2013-07-05 01:29:25
#Run Time: 1420
#Run Memory: 4456
#ZOJ User: calvinxiao
*/

#include<stdio.h>
#include<memory.h>

const int md = 1000000007;
int f[100002], dp[1000002];

void init() {
    f[0] = 1;
    int i;
    for (i = 1; i < 100002; i++) {
        f[i] = f[i-1] - md + f[i-1];
        if (f[i] < 0)
            f[i] += md;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    init();
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        memset(dp, 0, sizeof dp);
        int i;
        dp[m] = 1;
        for (i = m + 1; i <= n; i++) {
            dp[i] = dp[i-1] - md + dp[i-1];
            if (dp[i] < 0)
                dp[i] += md;
            int t = f[i-m-1] - dp[i-m-1];
            if (t < 0)
                t += md;
            dp[i] = dp[i] - md + t;
            if (dp[i] < 0)
                dp[i] += md;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
