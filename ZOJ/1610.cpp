/*
#Problem ID: 1610
#Submit Time: 2012-10-09 14:26:48
#Run Time: 60
#Run Memory: 412
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

#define FOR(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

int tree[50000];
int n, a, b, c;
int ans[8005];
const int LEN = 8003;
int pre;

void build(int l, int r, int rt) {
	if(l == r) {
		tree[rt] = 0;
		return;
	}

	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}

void update(int c, int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		tree[rt] = c;
		return;
	}

	int mid = (l + r) >> 1;
	if(tree[rt]) {
		tree[rt << 1] = tree[rt << 1 | 1] = tree[rt];
		tree[rt] = 0;
	}

	if(L <= mid) update(c, L, R, l, mid, rt << 1);
	if(mid < R)  update(c, L, R, mid + 1, r, rt << 1 | 1);
}

void query(int l, int r, int rt) {
	if(l == r) {
		//printf("node %d %d\n", l, tree[rt]);
		//ans[tree[rt] - 1] += 1;
		if(tree[rt] != pre) {
			if(pre) {
				ans[pre - 1] += 1;
			}
		}

		pre = tree[rt];
		return;
	}

	if(tree[rt]) {
		tree[rt << 1] = tree[rt << 1 | 1] = tree[rt];
		tree[rt] = 0;
	}

	int mid = (l + r) >> 1;
	query(l, mid, rt << 1);
	query(mid + 1, r, rt << 1 | 1);
}

int main()
{
	while(~scanf("%d", &n)) {
		build(1, LEN, 1);
		memset(ans, 0, sizeof ans);
		
		for(int i = 0; i < n; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			a++; c++;
			update(c, a, b, 1, LEN, 1);
		}

		pre = 0;
		query(1, LEN, 1);
		for(int i = 0; i <= 8000; ++i) {
			if(ans[i]) {
				printf("%d %d\n", i, ans[i]);
			}
		}

		puts("");
	}
    return 0;
}
