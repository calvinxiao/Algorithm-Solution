/*
#Problem ID: 3384
#Submit Time: 2014-05-19 12:27:01
#Run Time: 0
#Run Memory: 284
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

int n, a[1005], b[1005], ans[1005];

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  while (~scanf("%d", &n)) {
    REP(i, n) scanf("%d", a + i);
    REP(i, n) scanf("%d", b + i);
    memset(ans, 0, sizeof ans);
    vector<int> v;
    int s = 0;
    REP(i, n) {
      s += a[i];
      if (b[i] >= s) {
        ans[i] += s;
        b[i] -= s;
        s = 0;
        if (b[i] > 0)
          v.push_back(i);
      }
      else {
        s -= b[i];
        ans[i] += b[i];
        b[i] = 0;
        bool good = true;
        while (s > 0) {
          if (v.empty()) {
            good = false;
            break;
          }
          int j = v.back();
          v.pop_back();
          if (b[j] >= s) {
            ans[j] += s;
            b[j] -= s;
            s = 0;
            if (b[j] > 0)
              v.push_back(j);
          }
          else {
            s -= b[j];
            ans[j] += b[j];
            b[j] = 0;
          }
        }
        if (!good)
          break;
      }
    }
    if (s > 0)
      puts("Myon");
    else {
      for (int i = 0; i < n; i++) {
        printf("%d%c", ans[i], i == n - 1?'\n':' ');
      }
    }
  }
	return 0;
}
