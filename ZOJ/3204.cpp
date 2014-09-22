/*
#Problem ID: 3204
#Submit Time: 2013-03-22 17:55:45
#Run Time: 120
#Run Memory: 300
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <algorithm>


#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(__typeof(e.begin()) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int maxn = 101;
const int inf = (1<<30) - 1;

struct edge {
	int a, b, c;
} e[maxn*maxn];

bool cmp(const edge &A, const edge B) {
	if (A.c < B.c)
		return 1;
	if (A.c == B.c) {
		if (A.a < B.a)
			return 1;
		if (A.a ==  B.a)
			return (A.b < B.b);
	}
	return 0;
}

int f[maxn], cnt, ecnt, n, tc, c, x, y, t;
pair<int, int> p[maxn];

int main()
{
	//freopen("0.in", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		ecnt = cnt = 0;
		REP(i, n) REP(j, n) {
			scanf("%d", &c);
			if (c) {
				e[ecnt].a = i;
				e[ecnt].b = j;
				e[ecnt++].c = c;
			}
		}
		sort(e, e + ecnt, cmp);
		REP(i, n) f[i] = i;
		REP(k, ecnt) {
			x = e[k].a; y = e[k].b;
			while (f[x] != f[f[x]]) f[x] = f[f[x]];
			while (f[y] != f[f[y]]) f[y] = f[f[y]];
			if (f[x] != f[y]) {
				f[f[x]] = f[y];
				p[cnt++] = make_pair(x, y);
			}
			if (cnt + 1 == n)
				break;
		}
		if (cnt + 1 == n) {
			sort(p, p + cnt);
			REP(i, cnt) {
				if (i)
					printf(" ");
				printf("%d %d", p[i].first + 1, p[i].second + 1);
			}
			printf("\n");
		} else {
			puts("-1");
		}
	}

	return 0;
}
