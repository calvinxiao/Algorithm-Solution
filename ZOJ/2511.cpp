/*
#Problem ID: 2511
#Submit Time: 2012-10-01 23:01:17
#Run Time: 570
#Run Memory: 188
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

struct gao {
	double v;
	int idx;
};

bool cmp(const gao &a, const gao &b) {
	if(a.v > b.v) return 1;
	else if(a.v == b.v && a.idx < b.idx) return 1;

	return 0;
}

int main()
{
	int n, m, k;
	while(cin >> n >> m >> k) {
		gao a[m];
		FOR(i, m) {
			a[i].v = 0.0;
			a[i].idx = i + 1;
		}

		FOR(i, n) {
			FOR(j, m) {
				float t;
				cin >> t;
				a[j].v += t;
			}
		}

		sort(a, a + m, cmp);
		vector<int> ans;
		FOR(i, k) {
			ans.push_back(a[i].idx);
		}

		sort(ans.begin(), ans.end(), greater<int>());

		FOR(i, k) {
			if(i) cout << ' ';
			cout << ans[i];
		}

		cout << endl;

	}
    return 0;
}
