/*
#Problem ID: 2274
#Submit Time: 2013-09-29 15:10:20
#Run Time: 330
#Run Memory: 192
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

const int N = 505;
int a[N], f[N], n, ans;

int gcd(int x, int y) {
	int t;
	while (y != 0)
		t = y, y = x % y, x = t;
	return x;
}

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

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif

	while (~scanf(" %d ", &n)) {
		REP(i, n) a[i] = read_int();
		memset(f, 0, sizeof f);
		REP(i, n) for (int j = i + 1; j < n; ++j) {
			if (gcd(a[i], a[j]) == 1) {
				f[i]++; f[j]++;
			}
		}
		ans = 0;
		REP(i, n) {
			ans += f[i] * (n - f[i] - 1);
		}
		printf("%d\n", n * (n-1) * (n-2) / 6 - ans / 2);
	}
	return 0;
}
