/*
#Problem ID: 3790
#Submit Time: 2014-06-05 13:47:58
#Run Time: 50
#Run Memory: 1052
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

pair<int, int> p[100005];

int main()
{
  #ifndef ONLINE_JUDGE
	freopen("0.in", "r", stdin);
  #endif
	int n, k;
	while (~scanf("%d%d", &n, &k)) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			p[i].first = get();
			p[i].second = i;
		}
		sort(p, p + n);
		for (int i = 0; i < n;) {
      int j = i;
      while (j < n && p[i].first == p[j].first)
        j++;
      int a = i, b = i;
      while (b < j) {
        int qty = b - a + 1;
        int len = p[b].second - p[a].second + 1;
        int q2d = len - qty;
        if (q2d <= k) {
          b++;
          if (ans < qty)
            ans = qty;
        }
        else
          a++;
      }
      i = j;
		}
		printf("%d\n", ans);
	}
	return 0;
}
