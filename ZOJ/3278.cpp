/*
#Problem ID: 3278
#Submit Time: 2012-11-27 15:43:24
#Run Time: 1120
#Run Memory: 1056
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

#define PARENT_CNT 300205
#define MAX 20000005

int n, m;
long long k;
int a[111111], b[111111];

int main()
{

	//freopen("0.in", "r", stdin);

	while(~scanf("%d%d%lld", &n, &m, &k)) {
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for(int i = 0; i < m; ++i) scanf("%d", &b[i]);
		sort(a, a+n);
		sort(b, b+m);

		long long L, R, MID, sum, t, ans;
		int l, r, mid;

		L = 1LL * a[0] * b[0];
		R = 1LL * a[n-1] * b[m-1];
		ans = R;
		while(L <= R) {
			MID = (L + R) / 2;
			sum = 0;
			for(int i = 0; i < n; ++i) {
				l = 0, r = m - 1;
				t = 0;
				while(l <= r) {
					mid = (l + r) / 2;
					if(1LL * a[i] * b[mid] >= MID) {
						t = m - mid;
						r = mid - 1;
					}
					else {
						l = mid + 1;
					}
				}
				sum += t;
			}
			if(sum >= k) {
				ans = MID;
				L = MID + 1;
			}
			else {
				R = MID - 1;
			}
		}
		printf("%lld\n", ans);
	}
	
    return 0;
}
