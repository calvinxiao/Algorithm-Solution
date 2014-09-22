/*
#Problem ID: 3010
#Submit Time: 2013-12-29 23:23:09
#Run Time: 0
#Run Memory: 292
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

int n, m, t, ti, c[11];
double f[11], s[1<<11];
bool inq[1<<11];

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  while (1) {
    cin >> n >> m;
    if (n + m == 0)
      break;
    for (int i = 0; i < n; i++) {
      c[i] = 0;
      c[i] |= 1 << i;
      cin >> t;
      for (int j = 0; j < t; j++) {
        cin >> ti;
        c[i] |= 1 << (ti-1);
      }
      cin >> f[i];
      f[i] = (100.0 - f[i]) / 100.0;
    }
    for (int i = 0; i < (1<<11); i++)
      s[i] = -1.0;
    memset(inq, 0, sizeof inq);
    int first = (1<<n) - 1;
    s[first] = 1.0;
    queue<int> q;
    q.push(first);
    inq[first] = 1;
    while (!q.empty()) {
      int top = q.front(); q.pop(); inq[top] = false;
      for (int i = 0; i < n; i++) {
          int next = top ^ c[i];
          if (s[next] < s[top] * f[i]) {
            s[next] = s[top] * f[i];
            if (!inq[next]) {
              q.push(next);
              inq[next] = 1;
            }
          }
      }
    }
    if (s[0] < -0.1)
      cout << -1 << endl;
    else
      printf("%.2f\n", 1.0 * m * s[0]);
  }
	return 0;
}
















