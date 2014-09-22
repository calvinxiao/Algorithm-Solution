/*
#Problem ID: 2672
#Submit Time: 2012-11-21 11:44:48
#Run Time: 2980
#Run Memory: 17764
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
#include <ext/hash_map>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;
using namespace __gnu_cxx;

const int MAX = 3000;

short dp[MAX][MAX];

int main()
{
	//freopen("0.in", "r", stdin);
	int n, a[MAX], ans0, ans1, maxLen = -1;
	bool first = true;
	while(~scanf("%d", &n)) {
		if(first) first = false;
		else printf("\n");
		hash_map<int, int> m;
		hash_map<int, int>:: iterator it;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			for(int j = i + 1; j < n; ++j)
				dp[i][j] = 1;
		}
		
		maxLen = 0;
		ans0 = 0;
		for(int j = n - 1; j > 0; --j) {
			for(int i = j - 1; i >= 0; --i) {
				it = m.find(a[i] + a[j]);
				if(it != m.end())
					dp[i][j] = dp[j][it->second] + 1;
				if(dp[i][j] > maxLen) {
					maxLen = dp[i][j];
					ans0 = i;
					ans1 = j;
				}
			}
			m[a[j]] = j;
		}

		printf("%d\n", maxLen + 1);
		int a0 = a[ans0], a1 = a[ans1];
		printf("%d", a0);
		for(int i = 0; i < maxLen; ++i) {
			a1 = a0 + a1;
			a0 = a1 - a0;
			printf(" %d", a0);
		}
		printf("\n");
		
	}
    return 0;
}
