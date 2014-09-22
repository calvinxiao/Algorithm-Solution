/*
#Problem ID: 2050
#Submit Time: 2013-05-28 23:44:33
#Run Time: 90
#Run Memory: 6204
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int BIG = 999999999;
vector<int> e[1<<16];
int d[2][1<<16], s[2], inq[1<<16];
int g[4][4];
int tc;
char c;

void SFPA() {
	REP(i, 2) REP(j, (1<<16)) {
		d[i][j] = BIG;
	}
	d[0][0] = d[1][(1<<16)-1] = 0;
	s[0] = 0;
	s[1] = (1<<16) - 1;
	REP(kk, 2) {
		memset(inq, 0, sizeof inq);
		queue<int> q; q.push(s[kk]);
		while (!q.empty()) {
			int fr = q.front(); q.pop(); inq[fr] = 0;
			REP(i, e[fr].size()) {
				int ne = e[fr][i];
				if (d[kk][ne] > d[kk][fr] + 1) {
					d[kk][ne] = d[kk][fr] + 1;
					if (!inq[ne]) {
						q.push(ne);
						inq[ne] = 1;
					}
				}
			}
		}
	}
}

int main()
{
	//freopen("0.in", "r", stdin);
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	REP(i, 4) REP(j, 4) {
		g[i][j] = i * 4 + j;
	}
	REP(k, (1<<16)) {

		REP(i, 4) REP(j, 4) {
			int t = k ^ (1 << g[i][j]);
			REP(dd, 4) {
				int ni = i + dx[dd], nj = j + dy[dd];
				if (0 <= ni && 0 <= nj && ni < 4 && nj < 4)
					t ^= 1 << g[ni][nj];
			}
			e[k].push_back(t);
		}
	}
	//puts("1");
	SFPA();

	scanf("%d", &tc);
	while (tc--) {
		int ss = 0;
		REP(i, 16){
			scanf(" %c", &c);
			if (c == 'b')
				ss |= 1 << i;
		}
		int ans = min(d[0][ss], d[1][ss]);
		if (ans == BIG) {
			puts("Impossible");
		} else
			printf("%d\n", ans);
		if (tc)
			puts("");
	}
    return 0;
}
