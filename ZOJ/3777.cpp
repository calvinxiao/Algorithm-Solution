/*
#Problem ID: 3777
#Submit Time: 2014-06-21 20:49:18
#Run Time: 500
#Run Memory: 8288
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

const int f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
const int N = 13;

int dp[1 << 12][501], p[N][N];
vector<int> ss[N+1];

int gcd(int a, int b) {
  while (a != 0 && b != 0) {
    int t = a % b; a = b; b = t;
  }
  return a;
}

inline int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return x;
}

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif

  for (int i = 0; i < (1<<N); i++) {
    int cnt = __builtin_popcount(i);
    ss[cnt].push_back(i);
  }

  int tc;
  //scanf("%d", &tc);
  tc = get();
  while(tc--) {
    int n, m;
    //scanf("%d%d", &n, &m);
    n = get(); m = get();
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < n; j++)
        //scanf("%d", &p[i][j]);
        p[i][j] = get();
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int si = 0; si < (int)(ss[i].size()); si++) {
        int s = ss[i][si];
        if ( (s & ((1<<n) - 1)) != s)
          break;
        for (int j = 0; j < n; j++) {
          if ( ((1<<j) & s) == 0 ) {
            for (int k = 0; k <= m; k++) {
              int v = k + p[i+1][j];
              if (v > m)
                v = m;
              dp[s | (1<<j)][v] += dp[s][k];
            }
          }
        }
      }
    }
    int cnt = dp[(1<<n) - 1][m];
    if (cnt == 0) {
      puts("No solution");
    }
    else {
      int g = gcd(cnt, f[n]);
      printf("%d/%d\n", f[n] / g, cnt / g);
    }

  }
	return 0;
}
