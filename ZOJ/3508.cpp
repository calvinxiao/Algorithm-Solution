/*
#Problem ID: 3508
#Submit Time: 2013-03-09 05:08:26
#Run Time: 50
#Run Memory: 220
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

const int MAX = 100;

int w[1001], mi[2501], ma[2501], v[2501], n, m, t;

void Sort(int l, int r) {
	int i = l, j = r, x =  ma[l+r>>1], y = mi[l+r>>1];
	do {
		while (ma[i] < x) i++;
		while (ma[j] > x) j--;
		if (i <= j) {
			int temp = ma[i]; ma[i] = ma[j]; ma[j] = temp;
			temp = mi[i]; mi[i] = mi[j]; mi[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (l < j) Sort(l, j);
	if (i < r) Sort(i, r);
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf("%d%d", &n, &m)) {
		memset(w, 0, sizeof w);
		memset(v, 0, sizeof v);
		REP(i, n) scanf("%d%d", &mi[i], &ma[i]);
		REP(i, m) {
			scanf("%d", &t);
			w[t]++;
		}
		Sort(0, n-1);
		int i = 0, j = 0, ans = 0;
		while (i < 1001) {
			if (w[i]) {
				bool good = false;
				for (j = 0; j < n; ++j) if (!v[j]) {
					if (mi[j] <= i && i <= ma[j]) {
						v[j] = 1;
						good = true;
						w[i]--;
						break;
					}
				}
				if (good) ans++;
				else i++;
			} else
				i++;
		}
		printf("%d\n", ans);
	}
    return 0;
}
