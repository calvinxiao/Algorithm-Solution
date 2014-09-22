/*
#Problem ID: 3703
#Submit Time: 2013-04-22 17:45:55
#Run Time: 10
#Run Memory: 612
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, T, n, t[55], v[55], dp[1005][55][2];

int main()
{
	//freopen("0.in", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &T, &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &t[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i]);
		}

		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j)
			{
				if (t[i] > t[j]) {
					int tt = t[i]; t[i] = t[j]; t[j] = tt;
					tt = v[i]; v[i] = v[j]; v[j] = tt;
				}
			}
		}
		//puts("YES\n");
		memset(dp, -1, sizeof dp);
		dp[0][0][0] = 0;
		dp[0][0][1] = 0;

		int ans = 0, cnt = 0, penalty = T * T;
		for (int k = 0; k < n; ++k)
		{
			if (v[k] < 0)
				continue;
			for (int i = T; i >= t[k]; --i) {
				int i2 = i - t[k];
				for (int j = k+1; j >= 1; --j) {
					if (dp[i2][j-1][0] != -1) {
						if (dp[i][j][0] < dp[i2][j-1][0] + v[k]) {
							dp[i][j][0] = dp[i2][j-1][0] + v[k];
							dp[i][j][1] = dp[i2][j-1][1] + i2 + t[k];
						} else if (dp[i][j] == dp[i2][j-1] + v[k]) {
							if (dp[i][j][1] > dp[i2][j-1][1] + i2 + t[k]) {
								dp[i][j][1] = dp[i2][j-1][1] + i2 + t[k];

							}
						}
					}

					if (ans < dp[i][j][0]) {
						ans = dp[i][j][0];
						penalty = dp[i][j][1];
						cnt = j;
					} else if (ans == dp[i][j][0] && cnt < j) {
						cnt = j;
						penalty = dp[i][j][1];
					} else if (ans == dp[i][j][0] && cnt == j && penalty > dp[i][j][1]) {
						penalty = dp[i][j][1];
					}
				}
			}
		}

		if (cnt == 0)
			penalty = 0;

		printf("%d %d %d\n", ans, cnt, penalty);
	}
	return 0;
}
