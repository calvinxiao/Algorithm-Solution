/*
#Problem ID: 2502
#Submit Time: 2013-11-04 01:04:39
#Run Time: 320
#Run Memory: 2832
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

typedef vector<int> vec;
typedef vector<vec> mat;

int n, t, v, id, cnt;
string s;
map<string, int> idx;

int ID(string ss)
{
  if (idx.find(ss) == idx.end())
    idx[ss] = id++;
  return idx[ss];
}

mat mul(mat A, mat B)
{
  int n = A.size(), m = A[0].size(), p = B[0].size();
  mat C = mat(n, vec(p, 0));
  REP(i, n) REP(j, p) {
    C[i][j] = 0;
    REP(k, m) {
      C[i][j] += A[i][k] * B[k][j];
      C[i][j] &= 1;
    }
  }
  return C;
}

mat power(mat A, int T)
{
  mat C = mat(n, vec(n, 0));
  REP(i, n) C[i][i] = 1;

  if (T == 0)
    return C;

  mat B = power(A, T/2);
  B = mul(B, B);
  C = mul(C, B);

  if (T & 1)
    C = mul(C, A);

  return C;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("0.in", "r", stdin);
#endif
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    id = 0;
    scanf("%d%d", &n, &t);
    idx.clear();
    mat g = mat(n, vec(n, 0));
    mat ori = mat(1, vec(n, 0));
    REP(i, n) {
      cin >> s >> v >> cnt;
      int x = ID(s);
      ori[0][x] = v;
      REP(j, cnt) {
        cin >> s;
        g[x][ID(s)]++;
      }
    }

    REP(i, n) g[i][i]++;

    ori = mul(ori, power(g, t-1));

    int ans = 0;
    REP(j, n) if (ori[0][j] & 1) {
      ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
