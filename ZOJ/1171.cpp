/*
#Problem ID: 1171
#Submit Time: 2013-04-22 11:57:00
#Run Time: 110
#Run Memory: 572
#ZOJ User: calvinxiao
*/

#include <cstdio>

using namespace std;

const int maxn = 100002;
int tc, n, i, ans1, ans2, a[maxn];
char c;

int go(int dir) {
	int flip = 0, ret = 0;
	for (i = 0; i < n; ++i) {
		if (!flip && dir == a[i])
			continue;
		else if (flip && dir != a[i])
			continue;
		else {
			++ret;
			flip ^= 1;
		}
	}
	return ret;
}

int main()
{
	//freopen("0.in", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf(" %c", &c);
			if (c == 'U')
				a[n-i-1] = 1;
			else
				a[n-i-1] = 0;
		}
		ans1 = go(0);
		ans2 = go(1);
		if (ans1 < ans2)
			printf("%d\n", ans1);
		else
			printf("%d\n", ans2);
		if (tc)
			printf("\n");
	}
	return 0;
}
