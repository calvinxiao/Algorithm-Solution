/*
#Problem ID: 3211
#Submit Time: 2014-05-09 13:52:26
#Run Time: 20
#Run Memory: 528
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

pair<int, int> p[255];
int dp[255][255];

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
  int tc; tc = get();
  //scanf("%d", &tc);
  while (tc--) {
    int n, m, ans = 0;
    n = get(); m = get();
    //scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      p[i].second = get();
      //scanf("%d", &p[i].second);
    for (int i = 1; i <= n; i++)
      p[i].first = get();
      //scanf("%d", &p[i].first);
    sort(p + 1, p + n + 1);

    for (int i = 1; i <= n; i++) {
      dp[0][i] = max(dp[0][i-1], p[i].second);
      ans = max(ans, dp[0][i]);
    }


    for (int i = 1; i < m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = dp[i][j-1];
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + p[j].second + p[j].first * i);
        ans = max(ans, dp[i][j]);
      }
    }

    printf("%d\n", ans);
  }
	return 0;
}
