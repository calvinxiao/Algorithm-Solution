/*
#Problem ID: 3286
#Submit Time: 2014-05-19 15:22:51
#Run Time: 40
#Run Memory: 4180
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

int n, cnt[1000006];
//vector<int> v[300];
int p[300];

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  for (int i = 2; i <= 1000000; i++)
    for (int j = i; j < 1000006; j += i) {
      ++cnt[j];
    }

  for (int i = 1; i < 1000006; i++) {
    //v[cnt[i]].push_back(i);
    int t = cnt[i];
    cnt[i] = p[cnt[i]];
    p[t]++;
  }

  while (~scanf("%d", &n)) {
    //printf("%d\n", lower_bound(v[cnt[n]].begin(), v[cnt[n]].end(), n) - v[cnt[n]].begin());
    printf("%d\n", cnt[n]);
  }
	return 0;
}
