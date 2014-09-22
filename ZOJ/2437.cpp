/*
#Problem ID: 2437
#Submit Time: 2014-05-20 13:43:02
#Run Time: 0
#Run Memory: 832
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

const int N = 202;
int g[N][N], n, tc;

vector<pair<int, int> > x[N], zero;

int abs(int a) {
  return a < 0?-a:a;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("0.in", "r", stdin);
#endif
  //scanf("%d", &tc);
  tc = get();
  for (int __ = 0; __ < tc; __++) {
    if (__)
      printf("\n");
    //scanf("%d", &n);
    n = get();
    zero.clear();
    for (int i = 0; i < n; i++)
      x[i].clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        //scanf("%d", &g[i][j]);
        g[i][j] = get();
        if (g[i][j])
          x[i].push_back(make_pair(j, g[i][j]));
        else
          zero.push_back(make_pair(i, j));
      }
    }
    for (int i = 0; i < zero.size(); i++) {
      int p = zero[i].first, q = zero[i].second;
      //printf("p: %d, q: %d\n", p, q);
      int d = 999, v = 0, cnt = 0;
      for (int j = 0; j < n; j++) {
        if (abs(j - p) > d)
          break;
        vector<pair<int, int> >::iterator it = lower_bound(x[j].begin(), x[j].end(), make_pair(q, 0));
        if (it != x[j].end()) {
          int k = it->first;
          int dd = abs(p - j) + abs(q - k);
          if (dd < d) {
            d = dd;
            v = it->second;
            cnt = 1;
          } else if (dd == d) {
            cnt++;
          }
          //printf(" %d %d %d %d %d %d\n", j, it->first, it->second, d, v, cnt);
        }
        if (it - x[j].begin() > 0) {
          it--;
          int k = it->first;
          int dd = abs(p - j) + abs(q - k);
          if (dd < d) {
            d = dd;
            v = it->second;
            cnt = 1;
          } else if (dd == d) {
            cnt++;
          }
          //printf(" %d %d %d %d %d %d\n", j, it->first, it->second, d, v, cnt);
        }

      }
      //printf(" %d %d %d\n", d, v, cnt);
      if (cnt == 1) {
        g[p][q] = v;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d%c", g[i][j], j == n - 1 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
