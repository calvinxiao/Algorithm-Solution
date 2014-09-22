/*
#Problem ID: 3418
#Submit Time: 2014-01-01 19:35:50
#Run Time: 10
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
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

int n, m, a[111], b[111];

inline int read_int(){
    int a=0;
    int b=1,c=getchar();
    if(c=='-')b=-1;
    else a=c-48;
    while((c=getchar())!=' '&&c!='\n')
        a=a*10+c-48;
    a*=b;
    return a;
}

int f(int x, int y) {
	return __builtin_popcount(x^y);
}

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
	int tc; scanf(" %d ", &tc);
	while (tc--) {
		scanf(" %d %d ", &n, &m);
		REP(i, n) a[i] = read_int();
		REP(i, m) b[i] = read_int();
		sort(a, a + n);
		REP(j, m) {
			int small = 99;
			int ans = -1;
			REP(i, n) {
			  int t = f(a[i], b[j]);
			  if (t < small) small = t, ans = a[i];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
