/*
#Problem ID: 3573
#Submit Time: 2013-03-09 13:58:07
#Run Time: 4570
#Run Memory: 416
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 15002;

int n, a[MAX << 2], start, end, damage;

void build(int L, int R, int rt) {
	a[rt] = 0;
	if (L == R) {
		return ;
	}
	int mid = (L+R)>>1;
	build(L, mid, rt << 1);
	build(mid + 1, R, rt << 1 | 1);
}

void pushdown(int rt) {
	if (a[rt]) {
        a[rt << 1] += a[rt];
        a[rt << 1 | 1] += a[rt];
		a[rt] = 0;
	}
}

void update(int v, int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		a[rt] += v;
	} else {
        pushdown(rt);
        int mid = (l+r) >> 1;
        //printf("%d %d %d %d %d\n", L, R, l, r, mid);
        if (L <= mid) update(v, L, R, l, mid, rt << 1);
        if (mid < R)  update(v, L, R, mid + 1, r, rt << 1 | 1);
	}
	//printf("%d %d %d %d %d %d\n", L, R, l, r, rt, a[rt]);
}

int query(int L, int R, int l, int r, int rt) {
    if (L == 4) {
        //printf("4: %d %d %d %d %d %d\n", L, R, l, r, rt, a[rt]);
    }
	if (L <= l && r <= R) {
		return a[rt];
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid) return query(L, R, l, mid, rt << 1);
	if (mid < R)  return query(L, R, mid + 1, r, rt << 1 | 1);
}

int main()
{
	//freopen("0.in", "r", stdin);

	while (~scanf("%d", &n)) {
		//puts("1");
		n++;
		build(1, n, 1);
		//puts("1");
		while (1) {
			scanf("%d%d%d", &start, &end, &damage);
			if (start == -1) break;
			start++; end++;
			update(damage, start, end, 1, n, 1);
		}

		vector<int> ans(1, -1);
		int maxE = 0;
		int maxI = 0;
		for (int i = 1; i <= n; ++i) {
			ans.push_back(query(i, i, 1, n, 1));
			//printf("%d %d\n", i, ans.back());
			if (maxE < ans.back()) {
				maxE = ans.back();
				maxI = i;
			}
		}

		int l = maxI, r = maxI;
		for (int i = n; i > r; --i) {
            if (ans[i] == maxE) {
                r = i;
                break;
            }
		}
		printf("%d %d\n", l-1, r-1);
	}
    return 0;
}
