/*
#Problem ID: 2520
#Submit Time: 2013-11-08 10:35:49
#Run Time: 400
#Run Memory: 404
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

int MAX, n, q[11111], a[11111], b[11111], cnt;

int f(int num) {
  int res = 1;
  for (int i = 2; i <= sqrt((double) num + 0.0001); i++) {
    if (num % i == 0) {
      res += i + num / i;
    }
  }
  return res;
}

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  while (cin >> q[n]) {
    MAX = max(MAX, q[n]);
    n++;
  }
  //cout << f(284) << endl;
  int num = 220;
  cnt = 1;
  while (cnt <= MAX) {
    int m = f(num);
    if (num < m && f(m) == num) {
      a[cnt] = num;
      b[cnt++] = m;
    }
    num++;
    //cout << cnt << ' ' << num << endl;
  }

  for (int i = 0; i < n; i++) {
    cout << a[q[i]] << ' ' << b[q[i]] << endl;
  }

	return 0;
}
