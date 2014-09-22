/*
#Problem ID: 2706
#Submit Time: 2012-11-20 13:21:12
#Run Time: 530
#Run Memory: 1584
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cmath>

#define BAD  1234567890

int a[120000];
long long sum[120000];

void push_down(int rt, int cnt) {
	if(a[rt] != BAD) {
		int temp = a[rt];
		a[rt << 1] = temp;
		a[rt << 1 | 1] = temp;
		sum[rt << 1] = (long long) temp * ((cnt + 1) >> 1);
		sum[rt << 1 | 1] = (long long) temp * (cnt >> 1);
	}
}

void push_up(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
	a[rt] = BAD;
	if(l == r) {
		scanf("%d", &a[rt]);
		sum[rt] = a[rt];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	push_up(rt);
} 

long long query(int L, int R, int l, int r, int rt) {
	long long ret = 0;
	if(L <= l && r <= R) {
		ret = sum[rt];
		return ret;
	}
	push_down(rt, r - l + 1);
	int mid = (l + r) >> 1;
	if(L <= mid) ret += query(L, R, l, mid, rt << 1);
	if(mid < R) ret += query(L, R, mid + 1, r, rt << 1 | 1);
	return ret;
}

void update(int x, int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		a[rt] = x;
		sum[rt] = (long long) x * (r - l + 1);
		return ;
	}
	push_down(rt, r - l + 1);
	if(a[rt] == x) return ;
	else a[rt] = BAD;
	int mid = (l + r) >> 1;
	if(L <= mid) update(x, L, R, l, mid, rt << 1);
	if(mid < R) update(x, L, R, mid + 1, r, rt << 1 | 1);
	push_up(rt);
}

void PRINT(int l, int r, int rt) {
	if(l == r) {
		if(l != 1) printf(" ");
		printf("%d", a[rt]);
		return ;
	}
	push_down(rt, r  - l + 1);
	int mid = (l + r) >> 1;
	PRINT(l, mid, rt << 1);
	PRINT(mid + 1, r, rt << 1 | 1);
}

int main()
{

	int tc, n, m, i, from, to;
	tc = 0;
	while(~scanf("%d%d", &n, &m)) {
		tc++;
		build(1, n, 1);
		long long original = sum[1];
		for(i = 0; i < m; i++) {
			scanf("%d%d", &from, &to);
			long long temp = query(from, to, 1, n, 1);
			long long newSum = sum[1];
			double d = (double) temp / (to - from + 1);
			int average = 0;
			if(newSum <= original) {
				average = ceil(d);
			}
			else {
				average = floor(d);
			} 
			update(average, from, to, 1, n, 1);

			/*
			printf("%I64d %I64d, %d\n", newSum, temp, average);
			PRINT(1, n, 1);
			printf("\n");
			*/
		}
		PRINT(1, n, 1);
		printf("\n\n");
	}

	return 0;
}