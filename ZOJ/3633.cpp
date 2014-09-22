/*
#Problem ID: 3633
#Submit Time: 2014-06-12 17:17:11
#Run Time: 390
#Run Memory: 13944
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

const int N = 500005;
int n, m, a[N], t[N*4];
pair<int, int> p[N];

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

void build(int l, int r, int rt) {
  t[rt] = 0;
  if (l == r) {
    return ;
  }
  int mid = l + r >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
}

void update(int x, int v, int l, int r, int rt) {
  if (l == r && x == l) {
    t[rt] = v;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid) update(x, v, l, mid, rt << 1);
  else update(x, v, mid + 1, r, rt << 1 | 1);
  t[rt] = max(t[rt << 1], t[rt << 1 | 1]);
}

int query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    //printf("%d %d %d %d %d\n", L, R, l, r, t[rt]);
    return t[rt];
  }

  int mid = l + r >> 1;
  int ret = 0;
  if (L <= mid) {
    int tmp = query(L, R, l, mid, rt << 1);
    if (ret < tmp) ret = tmp;
  }
  if (mid < R) {
    int tmp = query(L, R, mid + 1, r, rt << 1 | 1);
    if (ret < tmp) ret = tmp;
  }
  //printf("%d %d %d\n", l, r, ret);
  return ret;
}

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      //scanf("%d", a + i);
      a[i] = get();
      p[i].first = a[i];
      p[i].second = i + 1;
    }
    sort(p, p + n);
    build(1, n, 1);
    for (int i = 1; i < n; i++) {
      if (p[i].first == p[i-1].first) {
        update(p[i].second, p[i-1].second, 1, n, 1);
      }

    }
    //scanf("%d", &m);
    m = get();
    for (int i = 0; i < m; i++) {
      int l, r;
      //scanf("%d%d", &l, &r);
      l = get();
      r = get();
      int ans = query(l, r, 1, n, 1);
      if (ans >= l) {
        printf("%d\n", a[ans-1]);
      }
      else
        printf("OK\n");
    }
    printf("\n");
  }
	return 0;
}
