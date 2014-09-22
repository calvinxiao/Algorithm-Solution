/*
#Problem ID: 3519
#Submit Time: 2013-03-09 05:56:43
#Run Time: 40
#Run Memory: 180
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 100;

short int n, a[1001], i, ip, cnt;

int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf("%d%d", &n, &ip)) {
		memset(a, 0, sizeof a);
		int max = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &cnt);
			++a[cnt];
			if (max < cnt)
				max = cnt;
		}
		cnt = 0;
		//sort(a, a+n);
		i = ip + 1;
		while (i <= max) {
			if (!a[i] || i <= ip)
				++i;
			else {
				--a[i];
				ip += 2;
				++cnt;
			}
		}

		printf("%d\n", ip + (n - cnt));
	}
    return 0;
}
