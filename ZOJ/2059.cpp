/*
#Problem ID: 2059
#Submit Time: 2013-05-28 22:33:02
#Run Time: 60
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

int n;
short int a[101], f[2][2005], s;

inline short int max(short int x, short int y) {
	return x < y ? y : x;
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (1) {
		scanf("%d", &n);
		if (n < 0)
			break;
		s = 0;
		memset(f, -1, sizeof f);
		REP(i, n) {
			scanf("%d", a+i);
			s += a[i];
		}
		f[1][0] = 0;
		f[0][0] = 0;
		REP(i, n) {
			REP(j, s) {
				if (f[0][j] != -1) {
					f[1][j+a[i]] = max(f[1][j+a[i]], f[0][j]);
					if (a[i] > j) {
						f[1][a[i] - j] = max(f[1][a[i] - j], f[0][j] + j);
					} else {
						// a[i] <= j;
						f[1][j - a[i]] = max(f[1][j-a[i]], f[0][j] + a[i]);
					}
				}
			}
			REP(j, s)
				f[0][j] = f[1][j];
		}

		if (f[0][0] > 0)
			printf("%d\n", f[0][0]);
		else
			puts("Sorry");
	}
    return 0;
}
