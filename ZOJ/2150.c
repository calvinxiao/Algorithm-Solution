/*
#Problem ID: 2150
#Submit Time: 2013-04-14 23:13:49
#Run Time: 60
#Run Memory: 160
#ZOJ User: calvinxiao
*/

#include <stdio.h>

int tc, n, md, a, b, i;
int ans, ret, aa;

int main()
{
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &md, &n);
		ans = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &a, &b);
			if (a == 0) continue;
			ret = 1, aa = a % md;
			while (b) {
				if (b&1) {
					ret = ret * aa % md;
				}
				aa = aa * aa % md;
				b >>= 1;
			}
			ans += ret;
			if (ans >= md)
				ans -= md;
		}
		printf("%d\n", ans);
	}
	return 0;
}