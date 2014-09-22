/*
#Problem ID: 2158
#Submit Time: 2014-05-13 17:11:21
#Run Time: 1700
#Run Memory: 23916
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

int ans, len, f[2042];

pair<int, pair<int, int> > e[2000042];
char s[2042][100];

int find(int a) {
  if (a == f[a])
    return a;
  return f[a] = find(f[a]);
}

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
    int n;
    while (1) {
      scanf("%d", &n);
      if (n == 0)
        break;
      for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
      }

      len = strlen(s[0]);

      int idx = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          int cost = 0;
          for (int k = 0; k < len; k++)
            cost += s[i][k] != s[j][k];
          e[idx].first = cost;
          e[idx].second.first = i;
          e[idx].second.second = j;
          idx++;
        }
      }

      sort(e, e + idx);

      for (int i = 0; i < n; i++)
        f[i] = i;

      ans = 0;
      int cnt = 0;
      for (int i = 0; i < idx; i++) {
        int cost = e[i].first;
        int s = e[i].second.first, t = e[i].second.second;
        int fs = find(s), ft = find(t);
        if (fs == ft)
          continue;
        f[fs] = ft;
        ans += cost;
        cnt++;
        if (cnt == n - 1)
          break;
      }

      printf("The highest possible quality is 1/%d.\n", ans);

    }
	return 0;
}
