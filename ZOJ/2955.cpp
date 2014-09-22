/*
#Problem ID: 2955
#Submit Time: 2013-10-12 10:45:16
#Run Time: 20
#Run Memory: 232
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

int tc, n, d[101], f[11111], target;
const int BIG = 111111;
const int ma = 9998;

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &target);
		int mm = target;
		int maxD = 0;
		REP(i, n) scanf("%d", d+i);
		REP(i, n) maxD = max(maxD, d[i]);
		int cnt = 0;
		if (ma < target) {
			mm = (target - ma) % maxD + ma;
			cnt = (target - mm) / maxD;
		}
		REP(i, mm+1) f[i] = BIG;
		f[0] = 0;
		REP(i, n) {
			REP(j, mm) {
				if (f[j] != BIG) {
					f[j+d[i]] = min(f[j+d[i]], f[j] + 1);
				}
			}
		}
		int ans = BIG;
		if (f[mm] != BIG)
			ans = cnt + f[mm];
		printf("%d\n", (ans == BIG) ? -1:ans);
	}
	return 0;
}
