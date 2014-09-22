/*
#Problem ID: 2839
#Submit Time: 2013-03-18 12:58:17
#Run Time: 320
#Run Memory: 188
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
#include <cstdlib>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(__typeof(e.begin()) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

int main()
{
	//freopen("0.in", "r", stdin);
	int n, m, tc = 0;
	while (scanf("%d%d", &n, &m) && n && m) {
		tc++;
		set<int> S;
		REP(p, m+1) REP(q, m+1)
			S.insert(p*p*p + q*q*q);
		vector<int> L;
		FORE(itr, S)
			L.push_back(*itr);
		sort(L.begin(), L.end());
		int LEN = L.size();
		vector<pair<int, int> > ans;
		REP(i, LEN) REPN(j, i+1, LEN-1) {
			int b = L[j] - L[i];
			int c = L[j];
			bool good = true;
			REP(nn, n-2) {
				if (S.find(c+b) == S.end()) {
					good = false;
					break;
				}
				c += b;
			}
			if (good)
				ans.push_back(make_pair(b, L[i]));
		}
		if (tc > 1)
			puts("");
		printf("Case %d:\n", tc);
		sort(ans.begin(), ans.end());
		if (ans.size() == 0)
			printf("NONE\n");
		else
			REP(i, ans.size())
				printf("%d %d\n", ans[i].second, ans[i].first);
	}
    return 0;
}
