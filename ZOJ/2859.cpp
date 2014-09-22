/*
#Problem ID: 2859
#Submit Time: 2013-03-18 22:53:40
#Run Time: 3550
#Run Memory: 7568
#ZOJ User: calvinxiao
*/

#include <cstdio>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(__typeof(e.begin()) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int maxn = 90001;
const int inf = (1<<30) - 1;
int n, m, SX, SY, TX, TY, g[303][303], a[maxn<<2], c[maxn<<2][4], idx;

int cross(int a3, int b3, int a4, int b4) {
	if (TY < b3 || b4 < SY || a4 < SX || TX < a3)
		return 0;
	return 1;
}

void build(int sx, int sy, int tx, int ty, int rt) {
	if (sx == tx && sy == ty) {
		a[rt] = g[sx][sy];
		//printf("%d %d %d %d\n", sx, sy, rt, a[rt]);
		return;
	}

	a[rt] = inf;
	int mx = (sx + tx) >> 1, my = (sy + ty) >> 1;

	if (sx <= mx && sy <= my) {
		c[rt][0] = idx++;
		build(sx, sy, mx, my, c[rt][0]);
		if (a[rt] > a[c[rt][0]])
			a[rt] = a[c[rt][0]];
	}

	if (sx <= mx && my < ty) {
		c[rt][1] = idx++;
		build(sx, my+1, mx, ty, c[rt][1]);
		if (a[rt] > a[c[rt][1]])
			a[rt] = a[c[rt][1]];
	}

	if (mx < tx && sy <= my) {
		c[rt][2] = idx++;
		build(mx+1, sy, tx, my, c[rt][2]);
		if (a[rt] > a[c[rt][2]])
			a[rt] = a[c[rt][2]];
	}

	if (mx < tx && my < ty) {
		c[rt][3] = idx++;
		build(mx+1, my+1, tx, ty, c[rt][3]);
		if (a[rt] > a[c[rt][3]])
			a[rt] = a[c[rt][3]];
	}

}

int query(int sx, int sy, int tx, int ty, int rt) {
	//printf("%d %d %d %d %d %d\n", sx, sy, tx, ty, rt, a[rt]);
	if (SX <= sx && SY <= sy && tx <= TX && ty <= TY) {
		return a[rt];
	}

	int mx = (sx + tx) >> 1, my = (sy + ty) >> 1;
	int ret = inf, temp;

	if (sx <= mx && sy <= my && cross(sx, sy, mx, my)) {
		temp = query(sx, sy, mx, my, c[rt][0]);
		if (ret > temp)
			ret = temp;
	}

	if (sx <= mx && my < ty && cross(sx, my + 1, mx, ty)) {
		temp = query(sx, my + 1, mx, ty, c[rt][1]);
		if (ret > temp)
			ret = temp;
	}

	if (mx < tx && sy <= my && cross(mx+1, sy, tx, my)) {
		temp = query(mx+1, sy, tx, my, c[rt][2]);
		if (ret > temp)
			ret = temp;
	}

	if (mx < tx && my < ty && cross(mx+1, my+1, tx, ty)) {
		temp = query(mx+1, my+1, tx, ty, c[rt][3]);
		if (ret > temp)
			ret = temp;
	}
	
	return ret;
}

int main()
{
	//freopen("0.in", "r", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		REPN(i, 1, n) REPN(j, 1, n) scanf("%d", &g[i][j]);
		idx = 1;
		build(1, 1, n, n, 0);
		scanf("%d", &m);
		while (m--) {
			scanf("%d%d%d%d", &SX, &SY, &TX, &TY);
			printf("%d\n", query(1, 1, n, n, 0));
		}
	}
	return 0;
}
