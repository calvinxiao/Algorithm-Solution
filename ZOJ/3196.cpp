/*
#Problem ID: 3196
#Submit Time: 2013-09-26 09:14:35
#Run Time: 0
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

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int N = 11;
int t, n, k;
long long a[N], ans;

bool contains(long long num, int kk) {
	if (num == 0 && kk == 0)
		return true;
	while (num != 0) {
		if (num % 10 == kk)
			return true;
		num /= 10;
	}
	return false;
}

void dfs(long long v, int i) {
	if (i == n) {
		if (!contains(v, k)) {
			if (v > ans)
				ans = v;
		}
		return;
	}
	long long t = v;
	for (int j = i; j < n; j++)
		if (a[j] > 1)
			t *= a[j];
		else
			t += a[j];
	if (t < ans)
		return;
	dfs(v * a[i], i+1);
	dfs(v + a[i], i+1);
	long long vv = v - a[i];
	if (vv < 0)
		vv = -vv;
	dfs(vv, i+1);
	if (a[i] != 0)
		dfs(v / a[i], i+1);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("0.in", "r", stdin);
  #endif
  scanf("%d", &t);
  while (t--){
  	scanf("%d%d", &n, &k);
  	REP(i, n) scanf("%lld", a+i);
  	ans = -1LL;
  	dfs(a[0], 1);
  	if (ans == -1LL)
  		puts("No result");
  	else
  		printf("%lld\n", ans);
  }
  return 0;
}
