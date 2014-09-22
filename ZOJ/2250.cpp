/*
#Problem ID: 2250
#Submit Time: 2013-03-12 23:50:29
#Run Time: 100
#Run Memory: 220
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPN(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

const int maxn = 10001;
int a[maxn], n, m;
int f, s, k, total;

int main()
{
	//freopen("0.in", "r", stdin);
	while (1) {
		scanf("%d%d", &n, &m);
		if (n+m == 0)
			break;
		memset(a, 0, sizeof a);
		f = s = 0;
		total = n * m;
		while(total--) {
			scanf("%d", &k);
			a[k]++;
		}
		REP(i, maxn) if (a[i] > f)
			f = a[i];
		REP(i, maxn) if (a[i] != f && a[i] > s)
			s = a[i];
		REP(i, maxn) if (a[i] == s)
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}