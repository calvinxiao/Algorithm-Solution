/*
#Problem ID: 2091
#Submit Time: 2013-05-28 23:07:42
#Run Time: 70
#Run Memory: 204
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

int n;
int f[6500];

int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf("%d", &n)) {
		REPN(i, 1, n) scanf("%d", f+i);
		//double ans = 0.0;
		int a = 0, d = 0;
		int up = f[n], down = 1;
		for (int i = n; i > 1; i--) {
			a += f[i];
			++d;
			if (a * down > up * d)
				up = a, down = d;
			//ans = max(ans, (0.0 + a) / d);
		}
		printf("%.6f\n", 1.0 * up / down);
	}
    return 0;
}
