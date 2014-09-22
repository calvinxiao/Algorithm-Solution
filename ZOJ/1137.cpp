/*
#Problem ID: 1137
#Submit Time: 2013-03-09 22:58:36
#Run Time: 860
#Run Memory: 8012
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

const int MAX = 1000001;

int n, li[MAX], next[MAX], back[1001], v[1001], pn[1001], ans, cnt, a, b, idx;
char c;

void add(int i, int j) {
	li[back[i]] = j;
	next[back[i]] = idx;
	back[i] = idx;
	idx++;
}

int go(int u) {
	int ne = u;
	while (next[ne] != -1) {
		//printf("%d %d %d\n", u, ne, li[ne]);
		int j = li[ne];
		if (!v[j]) {
			v[j] = 1;
			if (pn[j] == -1 || go(pn[j])) {
				pn[j] = u;
				return 1;
			}
		}
		ne = next[ne];
	}
	return 0;
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf("%d", &n)) {
		memset(next, -1, sizeof next);
		REP(i, n) back[i] = i;
		idx = n;
		REP(i, n) {
			scanf("%d: (%d)", &a, &cnt);  
			//printf("%d %d %d\n", i, a, cnt);
			REP(j, cnt) {
				scanf("%d", &b);
				add(a, b);
				//add(b, a);
			}
		}
		REP(i, n) pn[i] = -1;
		ans = 0;
		REP(i, n) {
			memset(v, 0, sizeof v);
			ans += go(i);
		}
		//printf("%d\n", ans);
		printf("%d\n", n - (ans >> 1));
	}
    return 0;
}
