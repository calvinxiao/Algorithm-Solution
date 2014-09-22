/*
#Problem ID: 1951
#Submit Time: 2013-03-27 18:03:43
#Run Time: 50
#Run Memory: 1464
#ZOJ User: calvinxiao
*/

#include <cstdio>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(__typeof(e.begin()) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int maxn = 1000001;

bool b[maxn];
int p[78497], cnt;
int n, a, n2, i, j, f;

int main()
{
	//freopen("0.in", "r", stdin);
	for (i = 3; i < maxn; i += 2) if (!b[i]) {
		p[cnt++] = i;
		for (j = i + i; j < maxn; j += i) b[j] = 1;
	}
	while (~scanf("%d", &n) && n) {
		f = 0;
		n2 = (n >> 1) + 1;
		for (i = 0; i < cnt && p[i] < n2; i++) {
			j = n - p[i];
			if (!b[j]) {
				f = 1;
				printf("%d = %d + %d\n", n, p[i], j);
				break;
			}
		}

		if (!f) 
			puts("Goldbach's conjecture is wrong.");
	}

	return 0;
}
