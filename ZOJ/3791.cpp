/*
#Problem ID: 3791
#Submit Time: 2014-06-11 14:28:30
#Run Time: 0
#Run Memory: 312
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

const int N = 101;
const int mod = 1000000009;

int c[N][N];
int f[2][N];

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  c[0][0] = 1;
  for (int i = 1; i < N; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i-1][j-1] + c[i-1][j];
      if (c[i][j] >= mod)
        c[i][j] -= mod;
    }
  }

  int n, s, m;
  while(~scanf("%d%d%d", &n, &s, &m)) {
    string s1, s2;
    cin >> s1 >> s2;

    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (s1[i] != s2[i])
        cnt++;

    memset(f, 0, sizeof f);
    f[0][cnt] = 1;
    int cur = 0;
    for (int i = 0; i < s; i++) {
      for (int j = 0; j <= n; j++)
        f[cur^1][j] = 0;
      for (int j = 0; j <= n; j++) {
        if (f[cur][j]) {
          for (int k = 0; k <= min(j, m); k++) {
            int diff = j + m - k - k;
            f[cur ^ 1][diff] += ((long long)f[cur][j] * c[j][k] % mod) * c[n-j][m-k] % mod;
            if (f[cur ^ 1][diff] >= mod)
              f[cur ^ 1][diff] -= mod;
          }
        }
      }
      cur ^= 1;
    }

    printf("%d\n", f[cur][0]);
  }

	return 0;
}
