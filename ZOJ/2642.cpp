/*
#Problem ID: 2642
#Submit Time: 2013-05-05 02:38:33
#Run Time: 1720
#Run Memory: 9952
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 100005;
int n, a[MAX], t[MAX << 2], s[18][MAX];
long long sum[MAX];

void update(int x, int ll, int rr, int l, int r, int rt) {
	if (ll <= l && r <= rr) {
		t[rt] = x;
		return;
	}
	int m = l + r >> 1;
	if (ll <= m) update(x, ll, rr, l, m, rt << 1);
	if (m < rr ) update(x, ll, rr, m + 1, r, rt << 1 | 1);
	t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
}

int ask(int ll, int rr, int l, int r, int rt) {
	if (ll <= l && r <= rr) {
		return t[rt];
	}
	int m = l + r >> 1;
	int ret = 1000000000;
	if (ll <= m) ret = ask(ll, rr, l, m, rt << 1);
	if (m < rr ) ret = min(ret, ask(ll, rr, m + 1, r, rt << 1 | 1));
	return ret;
}

void initRMQ() {
	REPN(i, 1, n)
		s[0][i] = a[i];
	for (int j = 1; j < 18; ++j) {
		REPN(i, 1, n) {
			if (i + (1<<j) - 1 > n)
				break;
			s[j][i] = min(s[j-1][i], s[j-1][i + (1<<(j-1))]);
		}
	}
}

int RMQ(int i, int j) {
	if (i == j)
		return a[i];
	int len = 0;
	while ((1<<len) <= j - i + 1)
		len++;
	len--;
	return min(s[len][i], s[len][j-(1<<len)+1]);
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf("%d", &n)) {
		REPN(i, 1, n) {
			scanf("%d", &a[i]);
			//update(a[i], i, i, 1, n, 1);
			sum[i] = sum[i-1] + a[i];
		}
		initRMQ();
		int ansl, ansr;
		long long ansv = -1;
		REPN(i, 1, n) {
			int L = i, R = i;
			int l = 1, r = i, m;
			while (l < r + 1) {
				m = l + r >> 1;
				//int temp = ask(m, r, 1, n, 1);
				int temp = RMQ(m, r);
				//printf("%d %d %d\n", m, r, temp);
				if (temp >= a[i])
					L = m, r = m - 1;
				else
					l = m + 1;
			}
			l = i, r = n; 
			while (l < r + 1) {
				m = l + r >> 1;
				//int temp = ask(l, m, 1, n, 1);
				int temp = RMQ(l, m);
				// if (i == 4) {
				// 	printf("%d %d\n", temp, a[i]);
				// }
				if (temp >= a[i])
					R = m, l = m + 1;
				else
					r = m - 1;
			}
			long long tempSum = (sum[R] - sum[L-1]) * a[i];
			if (tempSum >= ansv) {
				ansv = tempSum;
				ansl = L;
				ansr = R;
			}
		}
		printf("%lld\n", ansv);
		printf("%d %d\n", ansl, ansr);
	}

    return 0;
}
