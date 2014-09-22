/*
#Problem ID: 2134
#Submit Time: 2013-06-15 12:21:57
#Run Time: 870
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
#include <time.h>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int N = 22;
int tc, TC, g[N][N], n, mask, ans, temp;

void doit1() {
	for (mask = 1; mask < (1<<n); mask += 2) {
		temp = 0;
		// REP(i, n) if ((1<<i) & mask) {
		// 	REP(j, n) if (!((1<<j) & mask))
		// 		temp += g[i][j];
		// }
		vector<int> vi, vj;
		REP(i, n) if ((1<<i) & mask) vi.push_back(i);
				  else vj.push_back(i);
		REP(i, vi.size())
			REP(j, vj.size())
				temp += g[vi[i]][vj[j]];
		if (ans < temp)
			ans = temp;
	}
}

void doit2() {
	srand(243);
	int f[22];
	REP(i, n) f[i] = 0;
	temp = 0;
	REP(i, 2000000) {
		int t = rand() % n;
		f[t] ^= 1;
		REP(j, n) {
			if (f[j] == f[t])
				temp -= g[t][j];
			else
				temp += g[t][j];
		}
		if (ans < temp)
			ans = temp;
	}
}

int main()
{
	//freopen("0.in", "r", stdin);
	scanf("%d", &TC);
	tc = 0;
	while (TC--) {
		if (tc)
			puts("");
		tc++;
		scanf("%d", &n);
		REP(i, n) REP(j, n) scanf("%d", &g[i][j]);
		ans = 0;
		if (n < 17)
			doit1();
		else {
			doit2();
		}
		printf("%d\n", ans);
	}
    return 0;
}
