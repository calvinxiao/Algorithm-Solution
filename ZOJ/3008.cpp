/*
#Problem ID: 3008
#Submit Time: 2013-11-11 10:29:44
#Run Time: 20
#Run Memory: 272
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

using namespace std;

int main() {
  //freopen("0.in", "r", stdin);
  int n, m;

  while(~scanf("%d%d", &n, &m)) {
    if (n == 1)
      printf("1\n");
    else {
      int sq = (int)(sqrt((double)n + 0.00001));
      set<long long> s1, s2, s3;
      for (int i = 1; i <= sq; i++) {
        if (n % i == 0) {
          s1.insert(i);
          s1.insert(n/i);
        }
      }
      s2.insert(1);
      s3 = s2;

      for (int i = 0; i < m; i++) {
        for (__typeof(s1.begin()) i1 = s1.begin(); i1 != s1.end(); i1++) {
          long long p1 = *i1;
          for (__typeof(s2.begin()) i2 = s2.begin(); i2 != s2.end(); i2++) {
            long long p2 = *i2;
            long long p3 = p1 * p2;
            if (p3 <= (long long)n) {
              //cout << p1 << ' ' << p2 << ' ' << p3 << endl;
              s3.insert(p3);
            }
          }
        }
        s2 = s3;
      }

      printf("%d\n", s2.size());
    }
  }
  return 0;
}
