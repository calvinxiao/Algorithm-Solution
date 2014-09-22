/*
#Problem ID: 3212
#Submit Time: 2012-11-27 14:16:55
#Run Time: 170
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <cstring>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

#define PARENT_CNT 300205
#define MAX 20000005

int tc, n, m, k, a[17][17];

int main()
{

	//freopen("0.in", "r", stdin);
	
	int tc, n, m, k, a[17][17];
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0; i <= n+1; ++i) {
			for(int j = 0; j <= m+1; ++j) {
				a[i][j] = 1;
			}
		}

		int sum = 0;
		for(int i = 1; i < n-1; ++i) {
			for(int j = 1; j < m-1; ++j) {
				if(sum == k) {
					break;
				}
				a[i][j] = a[i+1][j] = a[i-1][j] = a[i][j+1] = a[i][j-1] = 0;
				sum++;
			}
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(j == 0) printf("%d", a[i][j]);
				else printf(" %d", a[i][j]);
			}
			puts("");
		}

	}
	
    return 0;
}
