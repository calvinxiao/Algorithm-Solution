/*
#Problem ID: 2921
#Submit Time: 2013-10-11 20:52:10
#Run Time: 210
#Run Memory: 1360
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

const int N = 100005;
int n, x[N], p[N], m[N], qty[111];
int tc;

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
	tc = read_int(); //scanf("%d", &tc);
	while (tc--) {
		n = read_int(); //scanf("%d", &n);
		REP(i, 111) qty[i] = 0; 
		REP(i, n) {
			x[i] = read_int();
			p[i] = read_int();
			m[i] = read_int();
			qty[p[i]] = 1;
		}
		//scanf("%d%d%d", x+i, p+i, m+i), qty[p[i]] = 1;
		int ans = 0;
		for (int price = 100; price >= 0; price--) {
			if (qty[price]) {
				int took = 0;
				int capa = 0;
				for (int i = n - 1; i >= 0; i--) {
					if (p[i] == price)
						capa += m[i];
					int minq = min(x[i], capa);
					took += minq;
					x[i] -= minq;
					capa -= minq;
				}
				ans += took * price;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
