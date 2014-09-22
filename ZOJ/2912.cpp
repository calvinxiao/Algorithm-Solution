/*
#Problem ID: 2912
#Submit Time: 2012-10-03 16:21:14
#Run Time: 160
#Run Memory: 684
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

int tc, n, cnt[10010], v[10010], edge[10010][3], top, next, a, b, c, i, j, k, sz, MIN;
int stk[10010], sp;
double ans;

int main()
{
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		memset(v, 0, sizeof v);
		ans = 0;
        sp = 0;
		vector<int> adj[10010];
		for(i = 0; i < n-1; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			edge[i][0] = a;
			edge[i][1] = b;
			edge[i][2] = c;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		stk[sp++] = 0;
		while(sp) {
			top = stk[sp-1];
			v[top] = true;

			vector<int> &vii = adj[top];
			sz = vii.size();

			for(j = 0; j < sz; ++j) {
				if(!v[vii[j]]) {
					stk[sp++] =(vii[j]);
				}
			}
			if(top == stk[sp-1]) {
				sp--;
				cnt[top] = 1;
				sz = vii.size();
				for(j = 0; j < sz; ++j)
					cnt[top] += cnt[vii[j]];
			}
		}

		for(i = 0; i < n-1; ++i) {
			MIN = min(cnt[edge[i][0]], cnt[edge[i][1]]);
			ans += (double)MIN * (n - MIN) * edge[i][2];
		}

		printf("%f\n", ans * 2.0 / n / (n-1));

	}
    return 0;
}
