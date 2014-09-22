/*
#Problem ID: 2027
#Submit Time: 2013-06-16 01:10:03
#Run Time: 0
#Run Memory: 188
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

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 100;

int main()
{
	//freopen("0.in", "r", stdin);
	string s, t;
	while (cin >> s >> t) {
		int n; cin >> n;
		vector<string> vs;
		vs.push_back(s), vs.push_back(t);
		vector<string> F, T;
		vector<int> c;
		REP(i, n) {
			string a, b; int C; cin >> a >> b >> C;
			F.push_back(a);
			T.push_back(b);
			c.push_back(C);
			vs.push_back(a); vs.push_back(b);
		}
		sort(vs.begin(), vs.end());
		map<string, int> mp;
		int idx = 0;
		mp[vs[0]] = idx++;
		REPN(i, 1, vs.size() - 1) {
			if (vs[i] != vs[i-1]) {
				mp[vs[i]] = idx++;
			}
		}
		vector<int> e[222];
		int g[222][222];
		memset(g, 0, sizeof g);
		REP(i, F.size()) {
			int ss, tt;
			ss = mp[F[i]]; tt = mp[T[i]];
			g[ss][tt] = c[i];
			e[ss].push_back(tt);
		}

		int cost[222], dis[222];
		REP(i, 222) cost[i] = 1e8, dis[i] = 0;

		queue<int> q;
		int inq[222];
		memset(inq, 0, sizeof inq);
		q.push(mp[s]);
		inq[mp[s]] = 1;
		cost[mp[s]] = 0;
		dis[mp[s]] = 0;

		while (!q.empty()) {
			int top = q.front(); q.pop(); inq[top] = 0;
			REP(i, e[top].size()) {
				int ne = e[top][i];
				int newcost = cost[top] + g[top][ne];
				int newdis = max(dis[top], g[top][ne]);
				if ((newcost - newdis < cost[ne] - dis[ne]) || (newcost - newdis == cost[ne] - dis[ne]) && newcost < cost[ne]) {
					cost[ne] = newcost;
					dis[ne] = newdis;
					if (!inq[ne]) {
						q.push(ne);
						inq[ne] = 1;
					}
				}
			}
		}
		int tidx = mp[t];
		printf("%d\n", cost[tidx] - dis[tidx]);
	}
    return 0;
}
