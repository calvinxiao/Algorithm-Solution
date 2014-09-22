/*
#Problem ID: 3708
#Submit Time: 2014-05-20 14:33:25
#Run Time: 20
#Run Memory: 764
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

const int N = 501;
short a[N], g[N][N], tc, n, m, x, y;


int main() {
#ifndef ONLINE_JUDGE
  freopen("0.in", "r", stdin);
#endif
  tc = get();
  for (int tcc = 1; tcc <= tc; tcc++) {
    n = get(), m = get();
    int e = 0;
    //memset(g, 0, sizeof g);
    for (int i = 0; i < m; i++)
      a[i] = get();
    for (int i = 0; i < m; i++) {
      int t = get();
      if(g[t][a[i]] != tcc)
        g[t][a[i]] = g[a[i]][t] = tcc, ++e;
    }
    printf("%.3f\n", (double)e / n);
  }
  return 0;
}
