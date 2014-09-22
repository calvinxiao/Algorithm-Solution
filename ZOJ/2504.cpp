/*
#Problem ID: 2504
#Submit Time: 2013-02-26 10:07:58
#Run Time: 120
#Run Memory: 4280
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

#define REP(i, n) for(int (i) = 0; (i) < (int)(n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int BIG = (int)1e9 + 7;

int t, n, m, k, a, b, c, inq[1005], dis[1005], g[1005][1005], mama[30005];
vector<int> e[1005], d[1005];

int main2() {
    bool good = true;
	int pre, next, motherDistance = 0;
    REPN(i, 2, k) {
        if (!g[mama[i-1]][mama[i]]) {
            good = false;
            break;
        }
        motherDistance += g[mama[i-1]][mama[i]];
    }
    if (mama[1] != 1 || mama[k] != n)
        good = false;

    if (k > 1 && good) {
        memset(inq, 0, sizeof inq);
        REPN(i, 1, n) dis[i] = BIG;
        queue<int> q;
        q.push(mama[2]); inq[mama[2]] = 1; dis[mama[2]] = 0;
        inq[1] = 1;//never walk back home....
        while (!q.empty()) {
            int top = q.front(); q.pop(); inq[top] = 0;
            REP(i, e[top].size()) {
                //cout << endl << top << endl;
                if (dis[e[top][i]] > dis[top] + d[top][i]) {
                    //printf("\n%d %d %d %d %d %d\n", top, i, e[top][i], dis[e[top][i]], dis[top], d[top][i]);
                    dis[e[top][i]] = dis[top] + d[top][i];
                    if (!inq[e[top][i]]) {
                        inq[e[top][i]] = 1;
                        q.push(e[top][i]);
                    }
                }
            }
        }
        if (dis[n] == BIG)
            good = false;
    }

	if (good) {
        if (k == 1)
            printf("Y 0\n");
        else
            printf("Y %d\n", motherDistance - dis[n] - g[mama[1]][mama[2]]);
	}
	else
		printf("N\n");
//    cout << motherDistance << ' ' << dis[n] << endl;
//    REPN(i, 1, n)
//        cout << dis[i] <<' ' ;
//    cout << endl;
    return 0;
}

int main()
{
	//freopen("0.in", "r", stdin);
	scanf("%d", &t);
	//cout << t << endl;
	REPN(tc, 1, t) {
		memset(g, 0, sizeof g);
		scanf("%d%d", &n, &m);
		//cout << n << ' ' << m << endl;
		REP(i, 1005) {
			e[i].clear();
			d[i].clear();
		}
	//printf("\n%d %d\n", e[1].size(), d[1].size());

		REP(mm, m) {
			scanf("%d%d%d", &a, &b, &c);
			g[a][b] = g[b][a] = c;
			e[a].push_back(b);
			e[b].push_back(a);
			d[a].push_back(c);
			d[b].push_back(c);
		}
	//printf("\n%d %d\n", e[1].size(), d[1].size());
        scanf("%d", &k);
        REPN(i, 1, k)
            scanf("%d", &mama[i]);

		printf("TEST %d ", tc);
		main2();
	}
}
