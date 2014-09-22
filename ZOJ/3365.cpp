/*
#Problem ID: 3365
#Submit Time: 2014-05-19 11:56:50
#Run Time: 200
#Run Memory: 2712
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

int n, a[50005];

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif

  while (~scanf("%d", &n)) {
    map<int, int> dict;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      dict[a[i] - i]++;
    }
    int ans = 0, gap = 0;
    for (map<int, int>::iterator it = dict.begin(); it != dict.end(); it++) {
      if (it->second > ans) {
        ans = it->second;
        gap = it->first;
      }
    }

    printf("%d\n", n - ans);
    for (int i = 0; i < n; i++) {
      printf("%d%c", i + gap, i == n - 1 ? '\n' : ' ');
    }


  }
	return 0;
}
