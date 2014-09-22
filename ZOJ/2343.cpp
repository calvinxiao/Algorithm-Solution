/*
#Problem ID: 2343
#Submit Time: 2014-06-11 10:45:54
#Run Time: 20
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

int x[1234], k[1234];

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  int tc; scanf("%d", &tc);
  while (tc) {
    tc--;
    int n, m, y; scanf("%d%d%d", &n, &m, &y);
    REP(i, n) scanf("%d", x + i);
    int mm = m;
    REP(i, n) {
      k[i] = floor(1.0 * m * x[i] / y);
      mm -= k[i];
    }
    for (int j = 0; j < mm; j++) {
      int maxIdx = 0;
      double maxV = -999999;
      REP(i, n) {
        double oldV = 1.0 * x[i] / y - 1.0 * k[i] / m;
        double newV = 1.0 * x[i] / y - 1.0 * (k[i] + 1) / m;
        if (oldV < 0)
          oldV = -oldV;
        if (newV < 0)
          newV = - newV;
        double gap = oldV - newV;
        if (maxV < gap)
          maxIdx = i, maxV = gap;
      }
      k[maxIdx]++;
    }
    REP(i, n) {
      printf("%d%c", k[i], (i == n-1)?'\n':' ');
    }
    if (tc > 0)
      printf("\n");
  }
	return 0;
}
