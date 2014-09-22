/*
#Problem ID: 2892
#Submit Time: 2013-11-28 03:52:35
#Run Time: 80
#Run Memory: 8952
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

inline int read_int()
{
  int a=0;
  int b=1,c=getchar();
  if(c=='-')b=-1;
  else a=c-48;
  while((c=getchar())!=' '&&c!='\n')
    a=a*10+c-48;
  a*=b;
  return a;
}

int n, a[1111111], b[1111111];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("0.in", "r", stdin);
#endif
  while (1) {
    n = read_int();
    if (n == 0)
      break;
    for (int i = 0; i < n; i ++) {
      a[i] = read_int();
    }
    for (int len = 2; len <= n; len <<= 1) {
      int len2 = len >> 1;
      for (int i = 0; i < len2; i ++) {
        int *p = &a[i + len2];
        a[i] = (a[i] + *p) / 2;
        *p = a[i] - *p;
      }
      for (int i = 0; i < len2; i++) {
        b[i<<1] = a[i];
        b[i<<1|1] = a[i+len2];
      }
      for (int i = 0; i < len; i++)
        a[i] = b[i];
    }
    for (int i = 0; i < n; i++) {
      printf("%d%c", a[i], i == (n-1) ? '\n' : ' ');
    }
  }
  return 0;
}
