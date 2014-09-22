/*
#Problem ID: 2254
#Submit Time: 2013-05-05 13:01:41
#Run Time: 1280
#Run Memory: 5020
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, dp[1111][1111];
pair<int, int> a[1111], b[1111];

int main()
{
	//freopen("0.in", "r", stdin);
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; ++i)
			a[i].second = i, scanf("%d", &(a[i].first));
		for (int i = 1; i <= n; ++i)
			b[i].second = i, scanf("%d", &(b[i].first));
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);

		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n ;++j) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (a[i].second == b[j].second) );
				dp[i][j] = max(dp[i][j], dp[i][j-1]);
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
			}
		}
		printf("%d\n", dp[n][n]);
	}
	return 0;
}
