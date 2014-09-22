/*
#Problem ID: 2402
#Submit Time: 2013-06-07 00:57:10
#Run Time: 60
#Run Memory: 360
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
long long g[11][2020];

int main()
{
	//freopen("0.in", "r", stdin);

	for (int i = 1; i <= 2000; i++)
		g[1][i] = 1;
	for (int i = 2; i <= 10; ++i) {
		for (int j = i; j <= 2000; ++j) {
			for (int k = j >> 1; k >= i-1; k--) {
				g[i][j] += g[i-1][k];
			}

		}
	}

	int tc;
	scanf("%d", &tc);
	for (int c = 1; c <= tc; c++) {
		int n, m; scanf("%d%d", &n, &m);
		long long ans = 0;
		for (int i = 0; i <= m; ++i)
			ans += g[n][i];
		//"Case 1: n = 4, m = 10, # lists = 4"
		printf("Case %d: n = %d, m = %d, # lists = %lld\n", c, n, m, ans);
	}
    return 0;
}
